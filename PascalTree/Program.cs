public class Solution
{
    IList<int> GetRow(int row, IList<int> previous)
    {
        if (row == 2)
        {
            return new int[] { 1, 1 }.ToList();
        }
        List<int> values = new List<int>();
        values.Add(1);
        for (int i = 1; i < row-1; i++)
        {
            values.Add(previous[i-1] + previous[i]);
        }
        values.Add(1);
        return values;
    }
    public IList<IList<int>> Generate(int numRow)
    {
        IList<IList<int>> lista = new List<IList<int>>();
        lista.Add(new int[]{1}.ToList());
        for(int i = 2; i <= numRow; i++)
        {
            lista.Add(GetRow(i, lista[i-2]));
        }

        return lista;
    }

    static void Main()
    {
        int val = int.Parse(Console.ReadLine());
        Solution sol = new Solution();
        foreach (var row in sol.Generate(val))
        {
            foreach (var element in row)
            {
                Console.Write(element);
                Console.Write(" ");
            }
            Console.WriteLine();
        }
    }
} 
