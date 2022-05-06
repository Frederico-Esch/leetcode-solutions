using MyLinkedList;
namespace MergeTwoSorted;
public class Program
{
    public static ListNode MergeTwoLists(ListNode list1, ListNode list2)
    {
        ListNode result; ListNode current;
        ListNode? left = list1; ListNode? right = list2;

        if (list1 == null) return list2;
        if (list2 == null) return list1;

        if (list1.val < list2.val)
        {
            result = new ListNode(list1.val);
            left = left.next;
        }
        else {
            result = new ListNode(list2.val);
            right = right.next;
        }

        current = result;
        while(left != null && right != null)
        {
            if (left.val < right.val)
            {
                current.next = new ListNode(left.val);
                left = left.next;
            }
            else
            {
                current.next = new ListNode(right.val);
                right = right.next;
            }
            current = current.next;
        }

        while(left != null)
        {
            current.next = new ListNode(left.val);
            left = left.next;
            current = current.next;
        }

        while(right != null)
        {
            current.next = new ListNode(right.val);
            right = right.next;
            current = current.next;
        }

        return result;
    }
    public static void Main(string[] args)
    {
        ListNode list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        Console.WriteLine(MergeTwoLists(list1, list2));
    }
}
