class Node:
    def __init__(self, value):
        self.value = value
        self.nextNode = None

class LinkedList:
    def __init__(self):
        self.head = None

    # INSERT HEAD
    def insert_head(self, value):
        new_node = Node(value)
        new_node.nextNode = self.head
        self.head = new_node

    # INSERT TAIL
    def insert_tail(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            return
        traveler = self.head
        while traveler.nextNode != None:
            traveler = traveler.nextNode
        traveler.nextNode = new_node

    # DELETE HEAD
    def delete_head(self):
        if self.head is None:
            return
        self.head = self.head.nextNode

    # DELETE TAIL
    def delete_tail(self):
        if self.head is None:
            return
        if self.head.nextNode is None:
            self.head = None
            return
        traveler = self.head
        while traveler.nextNode.nextNode != None:
            traveler = traveler.nextNode
        traveler.nextNode = None

    # DELETE VALUE
    def delete_value(self, value):
        if self.head is None:
            return
        if self.head.value == value:
            self.head = self.head.nextNode
            return
        traveler = self.head
        while traveler!=None:
            if traveler.nextNode.value==value:
                traveler.nextNode=traveler.nextNode.nextNode
                return 
            traveler = traveler.nextNode

    def total(self):
        traveler = self.head
        total = 0
        while traveler != None:
            total+=traveler.value
            traveler=traveler.nextNode
        return total
    
    def count(self):
        traveler=self.head
        count=0
        while traveler != None:
            count+=1
            traveler=traveler.nextNode
        return count
    
    def max_val(self):
        if self.head is None:
            return None
        max=self.head.value
        traveler=self.head
        while traveler != None:
            if traveler.value>max:
                max = traveler.value
            traveler=traveler.nextNode
        return max

    def search(self,value):
        traveler = self.head
        position = 0
        while traveler != None:
            if traveler.value==value:
                return (True,position,traveler)
            traveler=traveler.nextNode
            position+=1
        return (False,-1,None)
    
    def print_list(self):
        traveler = self.head
        while traveler != None:
            print(traveler.value, end=" → ")
            traveler = traveler.nextNode
        print("None")

    def sort(self):
        if self.head is None:
            return 
        swapped = True

        while swapped:
            swapped = False
            traveler = self.head
            while traveler.nextNode!=None:
                if traveler.value>traveler.nextNode.value:
                    traveler.value,traveler.nextNode.value=traveler.nextNode.value,traveler.value
                    swapped = True
                traveler=traveler.nextNode

    def update(self,current_val,new_val):
        traveler = self.head
        while traveler!= None:
            if traveler.value==current_val:
                traveler.value=new_val
                return True
            traveler=traveler.nextNode
        return False
    
    def update_at(self,position,new_val):
        traveler=self.head
        current_position=0
        while traveler!=None:
            if current_position==position:
                traveler.value=new_val
                return True
            traveler=traveler.nextNode
            current_position+=1

        return False
    
    def reverse(self):
        prev=None
        current=self.head
        while current!=None:
            next_node=current.nextNode
            current.nextNode=prev
            prev=current
            current=next_node
        self.head = prev


    
            
            

    



# ---- TEST ----
ll = LinkedList()
ll.insert_tail(10)
ll.insert_tail(20)
ll.insert_tail(30)
ll.insert_head(5)
ll.print_list()          # 5 → 10 → 20 → 30 → None

ll.delete_head()
ll.print_list()          # 10 → 20 → 30 → None

ll.delete_tail()
ll.print_list()          # 10 → 20 → None

ll.insert_tail(50)
ll.insert_tail(70)
ll.delete_value(50)
ll.print_list()          # 10 → 20 → 70 → None