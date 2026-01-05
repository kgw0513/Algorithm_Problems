using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        Queue<int> arr = new Queue<int>();
        int t;

        if (int.TryParse(Console.ReadLine(), out t))
        {
            for (int i = 1; i <= t; i++)
            {
                arr.Enqueue(i);
            }
            while(true)
            {
                Console.Write(arr.Dequeue());
                if (arr.Count == 0) break;
                Console.Write(' ');
                arr.Enqueue(arr.Dequeue());
            }
        }
    }
}