namespace MyLinkedList;
public class ListNode {
    public int val;
    public ListNode? next;
    public ListNode(int val = 0, ListNode? next = null)
    { 
        this.val = val;
        this.next = next;
    }

    public override string ToString()
    {
        StringWriter sw = new StringWriter();
        var current = this;
        while(current != null)
        {
            sw.Write($"{current.val} ");
            current = current.next;
        }
        sw.Write("\n");
        return sw.ToString();
    }
}
