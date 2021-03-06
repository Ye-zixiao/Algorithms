import edu.princeton.cs.algs4.StdOut;

public class KMPSubStrSearch {
    private String pat;
    private int[][] dfa;

    public void KMP(String pat) {
        this.pat = pat;
        int M = pat.length();
        int R = 256;
        dfa = new int[R][M];
        dfa[pat.charAt(0)][0] = 1;
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++)
                dfa[c][j] = dfa[c][X];
            dfa[pat.charAt(j)][j] = j + 1;
            X = dfa[pat.charAt(j)][X];
        }
    }

    public int search(String txt, String pat) {
        KMP(pat);
        int i, j, N = txt.length(), M = pat.length();
        for (i = 0, j = 0; i < N && j < M; i++)
            j = dfa[txt.charAt(i)][j];
        if (j == M) return i - M;
        else return -1;
    }

    public static void main(String[] args) {
        String txt = "hello world", pat = "world";
        KMPSubStrSearch kmpSubStrSearch = new KMPSubStrSearch();

        StdOut.println(kmpSubStrSearch.search(txt, pat));
        StdOut.println(txt.substring(kmpSubStrSearch.search(txt, pat)));
    }
}
