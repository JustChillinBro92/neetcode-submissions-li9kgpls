class Node {
public:
    int val;
    Node* next = nullptr;

    Node(int val_) {
        val = val_;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* temp = head->next;
        int count = 0;
        while(temp != nullptr) {
            if(count == index) return temp->val;
            count++;
            temp = temp->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if(newNode->next == nullptr) tail = newNode; 
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        Node* temp = head;
        int count = 0;
        while(count < index && temp->next != nullptr) {
            count++;
            temp = temp->next;
        }

        if(temp->next != nullptr) {
            if(temp->next == tail) tail = temp;
            Node* toDel = temp->next;
            temp->next = toDel->next;
            delete toDel;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* temp = head->next;
        while(temp != nullptr) {
            res.push_back(temp->val);
            temp = temp->next;
        }
        return res;
    }
};
