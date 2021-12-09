
int nextx[4] = {0, 1,  0, -1};
int nexty[4] = {1, 0, -1, 0};
bool visit(char maze[][n], int route[][n], int originX, int originY) {
    route[originX][originY] = 1;
    if ((originX == (n-1) && originY == (n-1)) )
        return 1;
    if (route[n-1][n-1] == 1)
        return 1;

    for(int arrow=0;arrow<4;arrow++){
        int newX = originX + nextx[arrow], newY = originY + nexty[arrow];
        if ((0 <= newX && newX < n) && (0 <= newY && newY < n) && (route[newX][newY] == 0)){
            if ( maze[newX][newY] == 'r'){
                route[newX][newY] = 1;
                // print_route(route);
                visit(maze, route, newX, newY);
            }else{
                route[newX][newY] = 0;
            }
        }
        if (route[n-1][n-1] == 1)
            return 1;
    }
    route[originX][originY] = 0;
    return 0;
}
