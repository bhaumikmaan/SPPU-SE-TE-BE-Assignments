### Set up the repository
1. Update the apt package index and install packages to allow apt to use a repository over HTTPS:

       sudo apt-get update
       sudo apt-get install \
          ca-certificates \
          curl \
          gnupg \
          lsb-release
2. Add Docker’s official GPG key:

        curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
        
3. Use the following command to set up the stable repository. To add the nightly or test repository, add the word nightly or test (or both) after the word stable in the commands below. Learn about nightly and test channels.

       echo \
        "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
        $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
        
### Install Docker Engine

1. Update the apt package index, and install the latest version of Docker Engine, containerd, and Docker Compose, or go to the next step to install a specific version:

       sudo apt-get update
       sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin

2. To install a specific version of Docker Engine, list the available versions in the repo, then select and install:
   - List the versions available in your repo:

         apt-cache madison docker-ce
   - Install a specific version using the version string from the second column, for example, 5:18.09.1~3-0~ubuntu-xenial.

         sudo apt-get install docker-ce=<VERSION_STRING> docker-ce-cli=<VERSION_STRING> containerd.io docker-compose-plugin

3. Verify that Docker Engine is installed correctly by running the hello-world image.

       sudo docker run hello-world
       

## Frequently used Docker commands with descriptions of what each does. 

### Docker container commands

* List all active containers
> docker ps           

* Lists containers (active or not)
> docker ps -a        

* Removes a container
> docker rm [container ID or shortname]          

* Removes a running container
> docker rm --force [container ID or shortname]           

* Stops a running container
> docker stop  [container ID or shortname]

* Starts a container
> docker start   [container ID or shortname]    

### Docker image commands

* List all images
> docker image

* To build an image and check containers run
> docker build --tag [shortname] . 

### Run a Docker container

* Use to start a container based on an image
>Docker run --publish 8000:8080 --detach --name [shortname] [appname]     


### Flags: 

* Asks Docker to forward traffic incoming on the host’s port 8000 to the container’s port 8080.  
`--publish 8000:8080`   

* Docker runs container in the background
`--detach` 

* For apps that aren't running a background process, this flag allocates a pseudo-TTY
`-t, --tty`       



## Example Node Docker image file

A Docker image file gives Docker a list of commands to execute. Below is an example Docker file for a Node.js application.

```dockerfile
#Tells Docker to use this Node version
FROM node:12.16.3

#Tells Docker to create folder called code inside Docker image
WORKDIR /code

#Environemnt variables can be accessed inside image
ENV  PORT 80

#Copies the package.json file into code folder
COPY package.json /code/package.json

#Runs node package manager and install dependencies
RUN npm install

#Copies all code from current working directory into code directory in image
COPY . /code

```

## Resources

* Getting started - Docker Docs
https://docs.docker.com/get-started/

* Dockerizing a Node.js web app - Node.js Documentation
https://nodejs.org/en/docs/guides/nodejs-docker-webapp/

* Docker 101: Fundamentals and Practice - FreeCodeCamp
https://www.freecodecamp.org/news/docker-101-fundamentals-and-practice-edb047b71a51/