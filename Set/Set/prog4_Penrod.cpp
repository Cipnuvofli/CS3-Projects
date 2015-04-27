//Student: Joseph Penrod
//Solution to Programming Homework 4
//CSCE 3110
//Instructor: Dr. Robert Renka


#include <iostream>
using namespace std;

template<typename Comparable>
class Set
{
    public:
    Set( );
    Set( const BinarySearchTree & rhs );
    ~Set( )
	{		
        makeEmpty( );
	}

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
	 /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }
    	
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( )
	{
		makeEmpty(root);
	}
     /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

      /**
     * Deep copy.
     */
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }
    

  private:
    struct BinaryNode
    {
       Comparable element;
       BinaryNode *left;
       BinaryNode *right;

       BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
         : element( theElement ), left( lt ), right( rt ) { }
    };
	int size;
    BinaryNode *root;

     /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            t = new BinaryNode( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
	}
       /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

     /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

     /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }

     /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
	}
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }
    void printTree( BinaryNode *t ) const
	{
	
	}
     /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
 
        return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }
};





int main()
{
    cout<<"Binary Search Tree tester program engaged.\n";
	int command = 0;
	while(command!=12)//This while loop makes it possible to test multiple infix expressions
	{
        Set<int> storage;
        cout<<"\n";
        cout<<"Enter a command:\n1. Insert Node\n2. Remove Node\n3.Find Minimum Node\n4. Find Maximum Node\n5. Check for presence of a value(Contains)\n6. Empty the tree\n7.Print the tree's contents\n8. Clone the Tree\n9. Test Begin Function\n10. Test End function\n11. Size of Set\n12.Exit Program\n\n";
        cout<<"The size of the set is: "<<storage.length()<<endl;
        if(!(cin>>command))//this conditional validates the input, preventing a char from creating an infinite loop
		{
			cout<<"Enter a number from 1 to 11: \n";
			cin.clear();
			cin.ignore(1000, '\n');

		}
		else
		{
		    switch(command)
		    {
		        case 1:
		        {
		            int insert;
					cout<<"What value are you trying to insert?\n";
					if(!(cin>>insert))
					{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');

					}
					else
					{
                            storage.insert(insert);
					}
                    break;

		        }
		        case 2:
                {
                    int remove;
					cout<<"What value are you trying to remove?\n";
					if(!(cin>>remove))
					{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');

					}
					else
					{
                            storage.remove(remove);
					}
                    break;

                }
		        case 3:
		        {
                    cout<<"The lowest node is: "<<storage.findMin()<<endl;
                    break;
		        }
		        case 4:
		        {
                    cout<<"The highest value in a node is: "<<storage.findMax()<<endl;
                    break;
		        }
		        case 5:
                {
                    int key;
					cout<<"What value are you searching for?\n";
					if(!(cin>>key))
					{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');

					}
					else if(storage.contains(key) == true)
					{
                            cout<<"Item found\n";
					}
					else
					{
                            cout<<"Item not found\n";
					}
                    break;

                }
		        case 6:
		        {
                    storage.makeEmpty();
                    break;
		        }
		        case 7:
                {
                    //storage.printTree();
                    break;
                }
		        case 8:
		        {
                    Set<int> Clone = storage;
                    //Clone.printTree();
                    cout<<"Clone function tested\n";
                    break;
		        }
		        case 9:
		        {
                    //cout<<"The value of the first Node is "<<storage.Begin()<<endl;
                    break;
		        }
		        case 10:
                {
                    //cout<<"The value of the last Node is"<<storage.End()<<endl;
                    break;
                }
		        case 11:
		        {
                    cout<<"The size of the set is: "<<storage.length()<<endl;
                    break;
		        }
		        case 12:

		        break;

		        default:

		        break;


		    }
		}
	}
}
