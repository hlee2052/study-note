# for Python 3

# python n=smallest and sorting

heap = [(1, 3), (9, 10) (9, 5), (1, 111)]
# snamllest will look at key, followed by second item (value)
result = heapq.nsmallest(3, heap)
print(result) # [(1, 3), (1, 111), (9, 5)]

