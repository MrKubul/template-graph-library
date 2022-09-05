pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'echo Building project...'
        sh 'chmod u+x scripts/Build.sh'
        sh 'scripts/Build.sh'
        archiveArtifacts artifacts: 'build/*', fingerprint: true
      }
    }

    stage('Test') {
      steps {
        sh 'echo Running Tests...'
        sh 'chmod u+x scripts/Test.sh'
        sh 'scripts/Test.sh'
      }
    }
  }
}