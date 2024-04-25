# Kubernetes


## Pods

## ReplicaSet

- replication controller - makes specified number of pods running
  - load balancing
- If resource runs o ut in node, then boots up more pods in another node
  - "runs across multiple pods"
- Replica Controller vs Replica Set
  - <b>controller being replaced with Replica Set</b>

- See <b>rc-definition.yaml </b>
- See <b> replica-definition.yaml </b>
  - note the "selector" section

Labels and Selectors
 - labels are used to filter 

Scale
 - kubectl replace -f replicaset-definition.yaml
 - kubectl scale --replicas=6 -f replicaset-definition.yaml
 - kubectl scale --replicas=6 <type> <name>
   - kubectl scale --replicas=6 replicaset myapp-replicaset

<b>Summary</b>
- kubectl create -f replicaset-definition.yaml
- kubectl get replicaset
- kubectl delete replicaset myapp-replicaset # also deletes all pods
- kubectl replace -f replicaset-definition.yaml
- kubectl scale -replicas=6 -f replicaset-definition.yaml # w/o changing file
- kubectl scale replicaset replicaset my-replica-set --replicas=6
- kubectl edit replicaset my-replica-set

## Deployments

- rolling update
- undo changes
- See <b> deployment-definition.yaml</b>
- kubectl get all
- kubectl create -f deployment-definition.yaml


## Namespace
- k8 creates these by default:
  1. default - when cluster is first set up
  2. kube-system - DNS, networking
  3. kube-public - resource that are public

- each namespace can have different policies, resources, etc
 
- example
  - default: 
    - web-pod
    - db-service
    - web-deployment
  - dev:
    - db-service
    - web-pod

  - within default:
    - mysql.connect("db-service")
  - calling dev
    - <b>mysql.connect("db-service.dev.svc.cluster.local")</b>
      - because when service is created, dns entry is added automatically in this format
      - \<service name\>.\<namespace\>.\<service\>.\<domain\>
        - service name: db-service
        - namespace: dev
        - service: svc
        - domain: cluster.local

  - can have namespace in metadata in file
  - see <b>namespace-dev.yaml</b>

- Can limit resource for a namespace
  - see <b>Compute-quota.yaml</b>


<b>Summary</b>
- kubectl get pods --namespace=kube-system
- kubectl create-f pod-definition.yaml --namespace=dev
- kubectl create namespace dev
- kubectl config set-context $(kubectl config current-context) --namespace=dev
- kubectl get pods --all-namespaces

## Imperative Commands
- --dry-run=client
  - will not create resource
- -o yaml

- kubectl run redis -l tier=db --image=redis:alpine  # label -l
- kubectl scale deployment nginx --replicas=4
  - can also scale

- Create a Service named redis-service of type ClusterIP to expose pod redis on port 6379
  - kubectl expose pod redis --port=6379 --name redis-service --dry-run=client -o yaml
    - uses pod's label as selector
  - kubectl create service clusterip redis --tpc=6379:6370 --dry-run=client -o yaml

- Create a Service named nginx of type NodePort to expose pod nginx's port 80 on port 30080 on the nodes:
  - kubectl expose pod nginx --port=80 --name nginx-service --type=NodePort --dry-run=client -o yaml
or
  - kubectl create service nodeport nginx --tcp=80:80 --node-port=30080 --dry-run=client -o yaml
