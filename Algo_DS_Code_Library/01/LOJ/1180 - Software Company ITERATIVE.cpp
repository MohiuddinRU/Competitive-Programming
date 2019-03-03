/// NORMALLY IT TAKES N^5 BUT WE HAVE TO MAKE IT IN N^4
/// WE WILL OPTIMIZE THE INNER N^2 LOOP.
/// INSTEAD IF CHECKING THE WHOLE (0,0) TO (R-1,C-1) GRID, WE WILL ONLY CHECK THE R-RP ROW AND C-CP COLUMN

int n,m, dp[103][103], prev[103][103];
int ratea[103], rateb[103];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) scanf("%d %d", &ratea[i], &rateb[i]);

        for(int i=0; i<=m; i++) for(int j=0; j<=m; j++) prev[i][j] = 55555;
        for(int i=0; i<=m; i++) for(int j=0; j<=m; j++) dp[i][j]   = 55555;
        prev[0][0] = 0;

        for(int i=0; i<n; i++) {

            for(int row=0; row<=m; row++) {
                int rp = 0;
                int cp = 0;
                for(int col=0; col<=m; col++) {
                    while( rp < row && max( prev[ row-rp-1 ][ col ] , (rp+1)*ratea[i] ) <= max( prev[ row-rp ][ col ] , (rp)*ratea[i] ) ) rp++;
                    while( cp < col && max( prev[ row ][ col-cp-1 ] , (cp+1)*rateb[i] ) <= max( prev[ row ][ col-cp ] , (cp)*rateb[i] ) ) cp++;

                    for(int r=0; r<=rp; r++) dp[row][col] = min( dp[row][col] , max( prev[ row-r ][ col-cp ] , r*ratea[i] + cp*rateb[i] ) ) ;
                    for(int c=0; c<=cp; c++) dp[row][col] = min( dp[row][col] , max( prev[ row-rp ][ col-c ] , rp*ratea[i] + c*rateb[i] ) ) ;
                }
            }

            for(int row=0; row<=m; row++)
                for(int col=0; col<=m; col++)
                    prev[row][col] = dp[row][col];
        }

        printf("Case %d: %d\n", t, prev[m][m]);
    }

    return 0;
}
