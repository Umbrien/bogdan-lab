using System;

namespace ConsoleApp1
{
    
    class RList
    {
        public class Node
        {
            public int Data;
            public Node Next;

            public Node(int d)
            {
                Data = d; 
            }
            
            public Node(int d, Node n)
            {
                Data = d;
                Next = n;
            }
        }

        public Node Root;

        public int Length
        {
            get
            {
                int length = 0;
                Node node = Root;
                while (node != null)
                {
                    node = node.Next;
                    length++;
                }
                return length;
            }
            set
            {
                if (value > Length )
                {
                    while (value >= Length)
                    {
                        Insert(0);
                        value--;
                    }
                }
                else
                {
                    if (value < 0) return;
                    
                    while (Length > value)
                    {
                        DeleteNode(Length);
                    }
                }
            }
        }

        public RList()
        {
        }

        public RList(int i)
        {
            Root = new Node(i);
        }

        public RList(int i, Node n) {
            Root = new Node(i, n);
        }
        
        public static RList operator +(RList l1, RList l2)
        {
            RList res = new RList();
            
            Node node = l1.Root;
            while (node != null)
            {
                res.Insert(node.Data);
                node = node.Next;
            }

            node = l2.Root;
            while (node != null)
            {
                res.Insert(node.Data);
                node = node.Next;
            }

            return res;
        }

        public static RList operator -(RList l1, RList l2)
        {
            RList res = new RList();
            
            Node node = l1.Root;
            while (node != null)
            {
                res.Insert(node.Data);
                node = node.Next;
            }
            
            node = l2.Root;
            while (node != null)
            {
                if (res.Search(node.Data) >= 0)
                {
                    res.DeleteNode(res.Search(node.Data) + 1);
                }
                node = node.Next;
            }
            return res;
        }

        public void Insert(int data)
        {
            if (Root == null)
            {
                Root = new Node(data);
                return;
            }
            Node current = Root;
            while (current.Next != null) current = current.Next;
            current.Next = new Node(data);
        }
        
        public void Insert(int data, int position) {
            Node node = new Node(data);
            
            if (Root == null && position != 0) return;
            if (position < 0 || position > Length) return;

            if (Root != null && position == 0) {
                node.Next = Root;
                Root = node;
                return;
            }

            Node current = Root;
            Node previous = null;

            for (int i = 0; i < position; i++) {
                previous = current;
                current = current.Next;

                if (current == null) break;
            }

            node.Next = current;
            previous.Next = node;
        }
        
        private Node recursiveDeleteNode(Node start, int n) 
        {
            if (n < 0) return start;
            if (start == null) return null;
            if (n == 0) return start.Next;

            start.Next = recursiveDeleteNode(start.Next, n-1); 
            return start;
        }

        public void DeleteNode(int n)
        {
            Root = recursiveDeleteNode(Root, n);
        }

        public void ClearList()
        {
            // Root = null;
            
            Length = 0;
        }

        private void recursiveReversePrintList(Node node)
        {
            if (node.Next != null)
            {
                recursiveReversePrintList(node.Next);
            }
            
            Console.Write(node.Data + " ");
        }

        public void ReversePrintList()
        {
            if (Root != null)
            {
                recursiveReversePrintList(Root);
                Console.WriteLine();
            }
        }

        private int searchRecursive(Node node, int el, int index)
        {
            if (node == null) return -1;
            if (node.Data == el) return index;
            if (node.Next == null) return -1;
            return searchRecursive(node.Next, el, index + 1);
        }

        public int Search(int el)
        {
            return searchRecursive(Root, el, 0);
        }
        
        private Node sortedMerge(Node a, Node b)
        {
            Node result;
            
            if (a == null) return b;
            if (b == null) return a;
            
            if (a.Data <= b.Data)
            {
                result = a;
                result.Next = sortedMerge(a.Next, b);
            }
            else
            {
                result = b;
                result.Next = sortedMerge(a, b.Next);
            }
            return result;
        }
        
        private Node getMiddle(Node h)
        {
            if (h == null) return null;
            
            Node fastptr = h.Next;
            Node slowptr = h;
            
            while (fastptr != null)
            {
                fastptr = fastptr.Next;
                if (fastptr != null)
                {
                    slowptr = slowptr.Next;
                    fastptr = fastptr.Next;
                }
            }
            return slowptr;
        }
 
        private Node MergeSort(Node h)
        {
            if (h == null || h.Next == null) return h;
            
            Node middle = getMiddle(h);
            Node middleNext = middle.Next;
            
            middle.Next = null;
            
            Node left = MergeSort(h);
            Node right = MergeSort(middleNext);
            
            Node sortedlist = sortedMerge(left, right);
            return sortedlist;
        }
        
        public void Sort()
        {
            Root = MergeSort(Root);
        }
    }

    class Program
    {
        private static void Main(string[] args)
        {
            RList l = new RList(1);
            l.Insert(5);
            l.Insert(2);
            l.Insert(3);
            l.Insert(4);
            l.ReversePrintList();
            l.Sort();
            l.ReversePrintList();
        }
    }
}
