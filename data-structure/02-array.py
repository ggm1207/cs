import ctypes


class Array(object):
    """
    array implementation class
    """

    def __init__(self):
        self.item_count = 0
        self.array_capacity = 1
        self.primary_array = self._create_array(self.array_capacity)

    def _create_array(self, array_capacity):
        """
        create new array with input capacity
        """
        return (array_capacity * ctypes.py_object)()

    def list(self):
        """
        list elements of array
        """
        for items in self.primary_array:
            return " ".join(str(self.primary_array[x]) for x in range(self.item_count))

    def __len__(self):
        """
        Returns numbers of items in array
        """
        return self.item_count

    def __getitem__(self, item_index):
        """
        Return element at index k
        """
        if not 0 <= item_index < self.item_count:
            return IndexError("index out of range!")
        return self.primary_array[item_index]

    def append(self, item):
        """
        Add new item to array, increase capacity if not available
        """
        if self.item_count == self.array_capacity:
            self._enlarge_array(2 * self.array_capacity)

        self.primary_array[self.item_count] = item
        self.item_count += 1

    def _enlarge_array(self, new_capacity):
        """
        create array with input capacity and copy the contents of old to new array
        """
        secondary_array = self._create_array(new_capacity)
        for i in range(self.item_count):
            secondary_array[i] = self.primary_array[i]

        self.primary_array = secondary_array
        self.array_capacity = new_capacity

    def delete(self, item_index):
        if 0 > item_index or item_index > self.item_count - 1:
            return IndexError("index out of range!")

        while 0 <= item_index < self.item_count - 1:
            self.primary_array[item_index] = self.primary_array[item_index + 1]
            item_index += 1
        self.item_count -= 1


x = Array()
x.append(10)
x.append(20)
x.append(30)
x.append(40)
x.append(50)
x.append(60)
x.append(70)

print(x.list())

x.delete(0)

print(x.list())

print(x.delete(7))

import sys

print(id(x))
print(id(x[0]))
print(sys.getsizeof(x[0]))
print(id(x[1]))
print(id(x[2]))
