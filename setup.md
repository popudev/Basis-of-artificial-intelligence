## Install Common Pre-requisites

- Git >= 2.31.0
- Kubernetes >= 1.14 and <= 1.21 (1.19.15)
- Kubectl Client v1.19.8
- HashiCorp Vault 1.7.1 and 1.7.3
- Docker >= 18.03.0
- Kubernetes Cluster >= 3 nodes

## Deploy Using Minikube v1.29.0

#### Step 1: Setup Minikube

1. Config minikube

```shell
minikube config set memory 4096
minikube config set kubernetes-version v1.19.15
```

2. Start minikube

```shell
minikube start --vm-driver=virtualbox \
--extra-config=apiserver.service-node-port-range=15000-20000 \
--nodes=3
```

#### Step 2: Clone forked repo

1. Fork repository https://github.com/hyperledger/bevel

2. Clone the forked repo to your machine

```shell
git clone git@github.com:<username_github>/bevel.git
```

3. Add a “local” branch to your machine

```shell
cd ~/bevel
git checkout -b local
git push -u origin local
```

#### Step 3: Setup folder build

1. Create a build folder inside your Bevel repository:

```shell
cd ~/bevel
mkdir build
```

2. Copy ca.crt, client.key, client.crt from ~/.minikube to build:

```shell
cp ~/.minikube/ca.crt build/
cp ~/.minikube/profile/minikube/client.key build/
cp ~/.minikube/profile/minikube/client.crt build/
```

3. Copy ~/.kube/config file to build:

```shell
cp ~/.kube/config build/
```

- NOTE: If you ever delete and recreate minikube, the above steps have to be repeated.

4.  <img src='./'>

5.  Copy gitops file from ~/.ssh to build. (This is the private key file which you used to authenticate to your GitHub in pre-requisites)

```shell
cp ~/.ssh/gitops build/
```
