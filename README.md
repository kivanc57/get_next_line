Turn on docker-compose

`docker-compose up`

Turn off docker-compose

`docker-compose down`

# OR

Build the Docker image

`docker build -f Dockerfile -t local-get_next_line:latest .`

Check if the image is created

`docker images`

Run the image as a container

`docker run --rm local-get_next_line:latest`

Check the container status

`docker ps`

Inspect the container interactively with bash

`docker run -it local-get_next_line:latest /bin/bash`
