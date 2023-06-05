int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int i = 1, j = 0;
    int platformsOccupied = 1;
    int platformsRequired = 1;

    sort(at, at + n);
    sort(dt, dt + n);

    while((i < n) && (j < n)){
        if(at[i] <= dt[j]){
            i++;
            platformsOccupied++;
        }

        else{
            j++;
            platformsOccupied--;
        }

        platformsRequired = max(platformsRequired, platformsOccupied);
    }
    return platformsRequired;
}
