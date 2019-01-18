/* Extension of smooth function to 2D array */

double **smooth (double **v_new, double **v, int n, double c)
{
    for (int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            v_new[i][j] = v[i][j] + c*(v[i-1][j]-2*v[i][j-1]-4*v[i][j]+v[i][j+1]+v[i+1][j]);
        }
    }
    v_new[0][0]= v[0][0];
    v_new[n-1][n-1] = v[n-1][n-1];
    
    return v_new;
}
