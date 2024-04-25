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