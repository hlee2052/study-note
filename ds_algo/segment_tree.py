class SegmentTree:
    def __init__(self, array):
        self.array = array
        self.tree = [0 for _ in range(4 * len(self.array))]

    def build(self, node, left, right):

        if left == right:
            self.tree[node] = self.array[left]
            return

        mid = (left + right)//2

        self.build(2 * node, left, mid)
        self.build(2 * node + 1, mid + 1, right)

        self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    def update(self, node, left, right, index, value):
        if left == right:
            self.array[index] += value
            self.tree[node] += value
            return

        mid = (left + right) //2

        if left <= index <= mid:
            self.update(2 * node, left, mid, index, value)
        else:
            self.update(2 * node + 1, mid + 1, right, index, value)

        self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

    # takes in tree range, and query range (left, right)
    def query(self, node, tree_left, tree_right, left, right):
        # out of bound
        if right < tree_left or tree_right < left:
            return 0

        if left <= tree_left and tree_right <= right:
            return self.tree[node]

        tree_mid = (tree_left + tree_right)//2

        return self.query(node * 2, tree_left, tree_mid, left, right) + self.query(2 * node + 1, tree_mid  + 1, tree_right, left, right)


if __name__ == "__main__":
    # based on https://www.geeksforgeeks.org/introduction-to-segment-trees-2/

    array = [0, 1, 3, 5, -2, 3]
    n = len(array)

    segment_tree = SegmentTree(array)
    segment_tree.build(1, 0, len(array) - 1)
    print(f"Sum of values in range 0-4 are: {segment_tree.query(1, 0, n - 1, 0, 4)}")

    segment_tree.update(1, 0, n - 1, 1, 100)
    print("Value at index 1 increased by 100")
    print(f"sum of value in range 1-3 are: {segment_tree.query(1, 0, n - 1, 1, 3)}")
