import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task2 solver = new Task2();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Task2 {
        BigInteger C(int n, int m) {
            BigInteger ans = BigInteger.valueOf(1);
            for (int i = 1; i <= m; i++) {
                ans = ans.multiply(BigInteger.valueOf(n - i + 1));
            }
            for (int i = 2; i <= m; i++) {
                ans = ans.divide(BigInteger.valueOf(i));
            }
            return ans;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                b[a[i]] = i;
            }
            ArrayList<Integer> arr = new ArrayList<>();
            int now = 1;
            for (int i = 2; i <= n; i++) {
                if (a[i - 1] != n && (a[i] == n || b[a[i - 1] + 1] > b[a[i] + 1])) {
                    arr.add(now);
                    now = 1;
                } else {
                    now++;
                }
            }
            arr.add(now);
            if (arr.size() > 26) {
                out.println(0);
            } else {
                int sz = arr.size();
                BigInteger[][] dp = new BigInteger[sz + 1][27];
                for (int i = 0; i <= sz; i++) {
                    for (int j = 0; j <= 26; j++) {
                        dp[i][j] = BigInteger.valueOf(0);
                    }
                }
                dp[0][0] = BigInteger.valueOf(1);
                for (int i = 0; i < sz; i++) {
                    for (int j = 0; j < 26; j++) {
                        for (int k = 1; j + k <= 26; k++) {
                            dp[i + 1][j + k] = dp[i + 1][j + k].add(dp[i][j].multiply(C(arr.get(i) + k - 2, k - 1)));
                        }
                    }
                }
                // out.println(dp[sz][26]);
                BigInteger ans = BigInteger.valueOf(0);
                for (int i = 1; i <= 26; i++) {
                    ans = ans.add(dp[sz][i]);
                }
                out.println(ans);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
