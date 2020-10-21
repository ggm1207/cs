import copy

class ArrayList:
    def __init__(self, max_list_size):
        self.arraylist = [0] * max_list_size
        self.length = 0
        self.max_list_size = max_list_size

    def is_empty(self):
        return self.length == 0

    def is_full(self):
        return self.length == self.max_list_size

    def add(self, position, item):
        """
        just practice, it's not perfect.
        """
        if not self.is_full() and position >= 0 and position < self.max_list_size:
            if self.arraylist[position] != 0:
                self.arraylist[position + 1 :] = self.arraylist[position:-1]
            self.arraylist[position] = item
            self.length += 1
        else:
            raise IndexError("Index Error!")

    def delete(self, position):
        if position < 0 or position >= self.max_list_size:
            raise IndexError("Index Error!")

        # for pos in range(position, self.length):
        # self.arraylist[pos-1] = self.arraylist[pos]

        self.arraylist[position:-1] = self.arraylist[position + 1 :]
        self.length -= 1


x = ArrayList(10)
print(x.is_empty())
x.add(3, 4)
x.add(0, 0)
x.add(1, 1)
x.add(2, 2)
print(x.arraylist)
x.add(3, 3)
print(x.arraylist)
x.delete(3)
print(x.arraylist)
print(x.length)
print("ArrayList" + "-" * 20)


class ListNode(object):
    def __init__(self, data=None):
        self.data = data
        self.link = None


def insert_node(head_node, prev_node, new_node):
    if head_node.link == None:
        head_node.link = new_node
    elif prev_node.data == None:
        new_node.link = head_node.link
        head_node.link = new_node
    else:
        new_node.link = prev_node.link
        prev_node.link = new_node


def delete_node(head_node, prev_node, removed_node):
    if prev_node.data == None:
        head_node.link = removed_node.link
    else:
        prev_node.link = removed_node.link


def search_node(head_node, x):
    cur_node = head_node
    while cur_node.link:
        cur_node = cur_node.link
        if cur_node.data == x:
            print("cur_node's data: {} and id: {}".format(x, id(cur_node)))


def concat_nodes(head1, head2):
    if head1.link == None:
        return head2
    elif head2.link == None:
        return head1
    else:
        p = head1
        while p.link:
            p = p.link

        p.link = head2.link
        return head1


def print_node(node):
    print(node.data, end=" ")
    if not node.link:
        return
    print_node(node.link)


h_node = ListNode()
node_1 = ListNode(1)
node_2 = ListNode(2)
node_3 = ListNode(3)
node_4 = ListNode(4)
node_5 = ListNode(5)

insert_node(h_node, h_node, node_1)
insert_node(h_node, node_1, node_2)
insert_node(h_node, node_2, node_3)
print_node(h_node)
print()
delete_node(h_node, node_1, node_2)
print_node(h_node)
search_node(h_node, 3)
print(id(node_3))

h2_node = ListNode()
insert_node(h2_node, h2_node, node_4)
insert_node(h2_node, h2_node, node_5)
print_node(h2_node); print()

new_node = concat_nodes(h_node, h2_node)
print_node(new_node); print()
