import java.io.StringWriter;

public class Main {
    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2));
        System.out.println(removeNthFromEnd(head, 2));
    }

    public static ListNode removeNthFromEnd(ListNode head, int n){
        ListNode fastPointer = head;
        ListNode slowPointer = head;
        for(int i = 0; i < n; i++){
            fastPointer = fastPointer.next;
        }
        while(fastPointer != null && fastPointer.next != null){
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next;
        }

        if(fastPointer == null){
            return slowPointer.next;
        }
        slowPointer.next = slowPointer.next.next;
        return head;
    }
}

class ListNode{
    public int val;
    public ListNode next;
    public ListNode(){}
    public ListNode(int val){this.val = val;}
    public ListNode(int val, ListNode next){
        this.val = val;
        this.next = next;
    }
    public String toString(){
        var current = this;
        StringWriter sw = new StringWriter();
        while(current != null){
            sw.write(current.val + " ");
            current = current.next;
        }
        return sw.toString();
    }
}