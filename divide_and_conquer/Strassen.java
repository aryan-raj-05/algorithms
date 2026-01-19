package divide_and_conquer;

//	Strassen's matrix multiplication method
//
//	say we have, 
//	matrices, X and Y, both of order (n x n), we can write them as,
//	X = [A, B],		and, Y = [E, F],
//		[C, D]				 [G, H]
//	where, A, B, C, D, E, F, G, H are sub-matrices of the order (n/2 x n/2)
//
//	now, we need to calculate 7 different products in a recursive way, those are
//	P1 = A * (F - H)
//	P2 = (A + B) * H
//	P3 = (C + D) * E
//	P4 = D * (G - E)
//	P5 = (A + D) * (E + H)
//	P6 = (B - D) * (G + H)
//	P7 = (A - C) * (E + F)
//
//	Now, the result of matrix multiplication X.Y is
//
//	X.Y = [P5 + P4 - P2 + P6    P1 + P2],
//		  [P3 + P4              P1 + P5 - P3 - P7]
public class Strassen {
    // For Simplicity,
    // Both A and B shall be square matrix and, their sizes in powers of 2
    // and no consideration will be given to optimize for memory
    public static int[][] matMul(int[][] mat1, int[][] mat2) {
        if (
            mat1.length != mat1[0].length || 
            mat2.length != mat2[0].length || 
            mat1.length != mat2.length
        ) throw new IllegalArgumentException();
        
        int n = mat1.length;
        if (!isPowerOfTwo(n) || n <= 0) throw new IllegalArgumentException();

        if (n <= 32) return naiveMatMul(mat1, mat2);

        int mid = n / 2;

        int[][] A = new int[mid][mid], B = new int[mid][mid];
        int[][] C = new int[mid][mid], D = new int[mid][mid];
        int[][] E = new int[mid][mid], F = new int[mid][mid];
        int[][] G = new int[mid][mid], H = new int[mid][mid];

        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                A[i][j] = mat1[i][j];
                B[i][j] = mat1[i][j + mid];
                C[i][j] = mat1[i + mid][j];
                D[i][j] = mat1[i + mid][j + mid];

                E[i][j] = mat2[i][j];
                F[i][j] = mat2[i][j + mid];
                G[i][j] = mat2[i + mid][j];
                H[i][j] = mat2[i + mid][j + mid];
            }
        }

        int[][] p1 = matMul(A, subtractMatrix(F, H));
        int[][] p2 = matMul(addMatrix(A, B), H);
        int[][] p3 = matMul(addMatrix(C, D), E);
        int[][] p4 = matMul(D, subtractMatrix(G, E));
        int[][] p5 = matMul(addMatrix(A, D), addMatrix(G, H));
        int[][] p6 = matMul(subtractMatrix(B, D), addMatrix(G, H));
        int[][] p7 = matMul(subtractMatrix(A, C), addMatrix(E, F));

        int[][] C11 = addMatrix(
            subtractMatrix(addMatrix(p5, p4), p2),
            p6
        );
        int[][] C12 = addMatrix(p1, p2);
        int[][] C21 = addMatrix(p3, p4);
        int[][] C22 = addMatrix(
            subtractMatrix(addMatrix(p5, p1), p3),
            p7
        );

        int[][] res = new int[n][n];

        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                res[i][j] = C11[i][j];
                res[i][j + mid] = C12[i][j];
                res[i + mid][j] = C21[i][j];
                res[i + mid][j + mid] = C22[i][j];
            }
        }

        return res;
    }

    private static int[][] naiveMatMul(int[][] mat1, int mat2[][]) {
        int n = mat1.length;
        int[][] res = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res[i][j] += mat1[i][k] * mat2[k][j];

        return res;
    }

    private static int[][] addMatrix(int[][] mat1, int[][] mat2) {
        int n = mat1.length;
        int[][] res = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = mat1[i][j] + mat2[i][j];

        return res;
    }

    private static int[][] subtractMatrix(int[][] mat1, int[][] mat2) {
        int n = mat1.length;
        int[][] res = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = mat1[i][j] - mat2[i][j];
            
        return res;
    }

    private static boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}
