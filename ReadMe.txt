1.) Make sure that the following packages are installed on your system:
 
 - build-essential package
 - g++
 - cmake
 - sun-java6-jdk
 - sun-java6-jre
 
2.) Download zookeeper: http://zookeeper.apache.org/ 
3.) Extract the downloaded file
4.) Create a directory /var/opt/zookeeper-data and enable write permissions to this directory
5.) Create a zoo.cfg file and place it in the conf directory of zookeeper: 

 tickTime=2000
 dataDir=/var/opt/zookeeper-data
 clientPort=2181
 
6.) Navigate to the bin directory of zookeeper and launch it via ./zkServer.sh start
7.) Navigate back to the example folder and compile the example:

cd build
cmake ..
make

6.) Run the example:

cd ../run
./start.sh