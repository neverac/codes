#include <iostream>
#include <string>
#include <queue>

using namespace std ;

struct Node
{
    int x , y ;
    bool black ;
} matrix [ 1000 ] [ 1000 ] ;

string arr [ 1000 ] ;

int main()
{
    int h , w , cnt = 0 , res = 0 ;
    cin >> h >> w ;
    for ( int i = 0 ; i < h ; i ++ )
        cin >> arr [ i ] ;
    queue<Node> q ;
    while ( !q.empty() )
        q.pop() ;
    for ( int i = 0 ; i < h ; i ++ )
    {
        for ( int j = 0 ; j < w ; j ++ )
        {
            matrix [ i ] [ j ].x = i ;
            matrix [ i ] [ j ].y = j ;
            matrix [ i ] [ j ].black = ( arr [ i ] [ j ] == '#' ) ;
            if ( matrix [ i ] [ j ].black )
            {
                q.push ( matrix [ i ] [ j ] ) ;
            }
        }
    }
    Node n ;
    while ( !q.empty() )
    {
        cnt = q.size() ;
        while ( cnt -- )
        {
            n = q.front() ;
            q.pop() ;
            if ( n.x > 0 )
            {
                if ( !matrix [ n.x - 1 ][ n.y ].black )
                {
                    matrix [ n.x - 1 ] [ n.y ].black = true ;
                    q.push ( matrix [ n.x - 1 ] [ n.y ] ) ;
                }
            }
            if ( n.y < w - 1 )
            {
                if ( !matrix [ n.x ] [ n.y + 1 ].black )
                {
                    matrix [ n.x ] [ n.y + 1 ].black = true ;
                    q.push ( matrix [ n.x ] [ n.y + 1 ] ) ;
                }
            }
            if ( n.x < h - 1 )
            {
                if ( !matrix [ n.x + 1 ] [ n.y ].black )
                {
                    matrix [ n.x + 1 ] [ n.y ].black = true ;
                    q.push ( matrix [ n.x + 1 ] [ n.y ] ) ;
                }
            }
            if ( n.y > 0 )
            {
                if ( !matrix [ n.x ] [ n.y - 1 ].black )
                {
                    matrix [ n.x ] [ n.y - 1 ].black = true ;
                    q.push ( matrix [ n.x ] [ n.y - 1 ] ) ;
                }
            }
        }
        res ++ ;
    }
    cout << res - 1 << endl ;
}
