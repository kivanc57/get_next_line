pipeline {
  agent any

  environment {
    DOCKERHUB_CREDENTIALS = credentials('dockerhub-credentials')
  }

  parameters {
    choice(name: 'VERSION', choices: ['1.0.0'], description: 'Select the version')
    booleanParam(name: 'executeTests', defaultValue: false, description: 'Execute tests')
  }


  stages {

    stage('Prepare') {
      steps {
        script {
          // Check out the repo
          checkout scm

          // Set up QEMU
          sh 'docker run --rm --privileged multiarch/qemu-user-static --reset -p yes'
        }
      }
    }
    stage('Build Docker Image') {
      steps {
        script {
          // Build Docker Image
          docker.build("kivanc57/get_next_line:latest", "-f Dockerfile .")
        }
      }
    }
  
    stage('Push Docker Image') {
      steps {
        script {
          // Log in to Docker Hub
          docker.withRegistry('https://index.docker.io/v1/', "${DOCKERHUB_CREDENTIALS}") {
            // Push Docker Image
            docker.image("kivanc57/get_next_line:latest").push('latest')
          }
        }
      }
    }

    stage('Test Docker Image') {
      when {
        expression { params.executeTests }
      }
      steps {
        sh 'docker run --rm kivanc57/get_next_line:latest <test>'
      }
    }
  }

  post {
    success {
      echo "Process Succesful"
    }

    failure{
      echo "Process Failed"
    }
  }
}
