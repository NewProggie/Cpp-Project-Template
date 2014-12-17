#!/usr/bin/env bash

PROJECT_NAME=`grep APPLICATION_NAME /vagrant/CMakeLists.txt | cut -d'"' -f2 | tr ' ' '_'`
JENKINS_UPDATE_URL=http://updates.jenkins-ci.org/latest/
JENKINS_PLUGINS_PATH=/var/lib/jenkins/plugins/
JENKINS_JOBS_PATH=/var/lib/jenkins/jobs/
JENKINS_USER=jenkins.jenkins
declare -a JENKINS_PLUGINS=("git" "cmakebuilder" "doxygen" "sloccount" "htmlpublisher")

installJenkinsPlugin() {
    if [ -f ${JENKINS_PLUGINS_PATH}${1}.hpi -o -f ${JENKINS_PLUGINS_PATH}${1}.jpi ]; then
        if [ "$2" == "1" ]; then
            return 1
        fi
        echo "Skipped Jenkins Plugin: $1 (already installed)"
        return 0
    else
        echo "Installing Jenkins Plugin: $1"
        curl -L --silent --output ${JENKINS_PLUGINS_PATH}${1}.hpi ${JENKINS_UPDATE_URL}${1}.hpi
        return 0
    fi
}

# install and configure jenkins ci
wget -q -O - https://jenkins-ci.org/debian/jenkins-ci.org.key | sudo apt-key add -
sh -c 'echo deb http://pkg.jenkins-ci.org/debian binary/ > /etc/apt/sources.list.d/jenkins.list'
apt-get update
apt-get install --no-install-recommends -y build-essential cmake ggcov lcov curl unzip sloccount git git-core jenkins doxygen ttf-dejavu libboost-dev libboost-program-options1.46-dev

# install necessary jenkins plugins
mkdir -p ${JENKINS_PLUGINS_PATH}
for plugin in "${JENKINS_PLUGINS[@]}"; do
    installJenkinsPlugin "$plugin"
done

changed=1
while [ "$changed"  == "1" ]; do
    echo "Check for missing dependecies ..."
    changed=0
    for f in ${JENKINS_PLUGINS_PATH}*.hpi ; do
        deps=$( unzip -p ${f} META-INF/MANIFEST.MF | tr -d '\r' | sed -e ':a;N;$!ba;s/\n //g' | grep -e "^Plugin-Dependencies: " | awk '{ print $2 }' | tr ',' '\n' | awk -F ':' '{ print $1 }' | tr '\n' ' ' )
        for plugin in $deps; do
            installJenkinsPlugin "$plugin" 1 && changed=1
        done
    done
done

chown ${JENKINS_USER} ${JENKINS_PLUGINS_PATH} -R
service jenkins restart

# install already configured jenkins job for this project
mkdir -p ${JENKINS_JOBS_PATH}${PROJECT_NAME}
cp /vagrant/tools/share/jenkins-config.xml ${JENKINS_JOBS_PATH}${PROJECT_NAME}/config.xml
chown ${JENKINS_USER} ${JENKINS_JOBS_PATH} -R
service jenkins restart
