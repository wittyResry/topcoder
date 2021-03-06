import java.io.*;
import java.util.*;

public class PotentialArithmeticSequence {
    boolean can(int[] a) {
        int pos = -1, maxValue = -1;
        int n = a.length;
        for (int i = 0; i < n; ++i) {
            if (maxValue == -1 || a[i] > maxValue) {
                pos = i;
                maxValue = a[i];
            }
        }
        if (maxValue > 10) maxValue = 10;
        for (int i = 0; i < n; ++i) {
            int dist = i - pos + (1 << maxValue) + (1 << 10);
            if (i != pos && Integer.numberOfTrailingZeros(dist) != a[i]) {
                return false;
            }
        }
        return true;
    }
	public int numberOfSubsequences(int[] d) {
        int n = d.length, res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int[] a = new int[j - i + 1];
                for (int k = i; k <= j; ++k) {
                    a[-i + k] = d[k];
                }
                if (can(a)) {
                    res++;
                }
            }
        }
		return res;
	}

// CUT begin
	public static void main(String[] args){
		System.err.println("PotentialArithmeticSequence (300 Points)");
		System.err.println();
		HashSet<Integer> cases = new HashSet<Integer>();
        for (int i = 0; i < args.length; ++i) cases.add(Integer.parseInt(args[i]));
        runTest(cases);
	}

	static void runTest(HashSet<Integer> caseSet) {
	    int cases = 0, passed = 0;
	    while (true) {
	    	String label = Reader.nextLine();
	    	if (label == null || !label.startsWith("--"))
	    		break;

            int[] d = new int[Integer.parseInt(Reader.nextLine())];
            for (int i = 0; i < d.length; ++i)
                d[i] = Integer.parseInt(Reader.nextLine());
            Reader.nextLine();
            int __answer = Integer.parseInt(Reader.nextLine());

            cases++;
            if (caseSet.size() > 0 && !caseSet.contains(cases - 1))
                continue;
    		System.err.print(String.format("  Testcase #%d ... ", cases - 1));

            if (doTest(d, __answer))
                passed++;
	    }
	    if (caseSet.size() > 0) cases = caseSet.size();
        System.err.println(String.format("%nPassed : %d/%d cases", passed, cases));

        int T = (int)(System.currentTimeMillis() / 1000) - 1503726093;
        double PT = T / 60.0, TT = 75.0;
        System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}

	static boolean doTest(int[] d, int __expected) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		PotentialArithmeticSequence instance = new PotentialArithmeticSequence();
		int __result = 0;
		try {
			__result = instance.numberOfSubsequences(d);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
			return false;
		}
		else if (__result == __expected) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			return true;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + __expected);
			System.err.println("           Received: " + __result);
			return false;
		}
	}

	static class Reader {
        private static final String dataFileName = "PotentialArithmeticSequence.sample";
	    private static BufferedReader reader;

	    public static String nextLine() {
	        try {
                if (reader == null) {
                    reader = new BufferedReader(new InputStreamReader(new FileInputStream(dataFileName)));
                }
                return reader.readLine();
	        }
	        catch (IOException e) {
	            System.err.println("FATAL!! IOException");
	            e.printStackTrace();
	            System.exit(1);
	        }
	        return "";
	    }
	}
// CUT end
}
