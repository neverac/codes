#include <iostream>
#include <queue>

using namespace std ;

int visited [ 1001 ] [ 2 ] ;
struct node
{
    int layerS = 0 , layerT = 0 ;
    node* ptr = NULL ;
} arr [ 1001 ] ;

int n , m , s , t , B , E , cnt ; node* p ;

bool findW ( int i , int j )
{
    p = arr [ i ].ptr ;
    while ( p != NULL )
    {
        if ( p->layerS == j )
            return true ;
        p = p->ptr ;
    }
    return false ;
}

int main()
{
    cin >> n >> m >> s >> t ;
    while ( m -- )
    {
        cin >> B >> E ;
        p = new node ;
        p->layerS = E ;
        p->ptr = arr [ B ].ptr ;
        arr [ B ].ptr = p ;

        p = new node ;
        p->layerS = B ;
        p->ptr = arr [ E ].ptr ;
        arr [ E ].ptr = p ;
    }
    queue<int> q ;
    q.push ( s ) ;
    while ( !q.empty() )
    {
        B = q.front() ;
        q.pop() ;
        p = arr [ B ].ptr ;
        //cout << arr [ B ].ptr->layerS << endl ;
        while ( p != NULL )
        {
            if ( !visited [ p->layerS ] [ 0 ] )
            {
                q.push( p->layerS ) ;
                arr [ p->layerS ].layerS = arr [ B ].layerS + 1 ;
                visited [ p->layerS ] [ 0 ] = 1 ;
            }
            p = p->ptr ;
        }
    }
    q.push ( t ) ;
    while ( !q.empty() )
    {
        E = q.front() ;
        q.pop() ;
        p = arr [ E ].ptr ;
        while ( p != NULL )
        {
            if ( !visited [ p->layerS ] [ 1 ] )
            {
                q.push( p->layerS ) ;
                arr [ p->layerS ].layerT = arr [ E ].layerT + 1 ;
                visited [ p->layerS ] [ 1 ] = 1 ;
            }
            p = p->ptr ;
        }
    }
    arr [ s ].layerS = 0 ;
    arr [ t ].layerT = 0 ;
    B = arr [ s ].layerT ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        for ( int j = i + 1 ; j <= n ; j ++ )
        {
            if ( !findW ( i , j ) && arr [ i ].layerS + arr [ j ].layerT + 1 >= B && arr [ i ].layerT + arr [ j ].layerS + 1 >= B )
            {
                cnt ++ ;
            }
        }
    }
    cout << cnt << endl ;
}
