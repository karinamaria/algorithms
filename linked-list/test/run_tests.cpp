#include<iostream>
#include<list>
#include <iterator>


#include "../lib/test_manager.h"
#include "../include/list.h"

#define which_lib sc
// ============================================================================
// TESTING list AS A CONTAINER OF INTEGERS
// ============================================================================

int main( void )
{
    TestManager tm{ "Intlist"};
    {
        BEGIN_TEST(tm,"DefaultConstructor", "default constructor");

        which_lib::list<int> list;
        
        EXPECT_EQ( list.size(), 0);
        EXPECT_TRUE( list.empty() );
    }

    {
        BEGIN_TEST(tm, "ConstructorSize", "Constructor size");

        which_lib::list<int> list(10);

        EXPECT_EQ(list.size(), 10);
        EXPECT_FALSE(list.empty());
    }


    {
        BEGIN_TEST(tm,"ListContructor", "initializer list constructor.");
       
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        EXPECT_EQ( list.size(), 5 );
        EXPECT_FALSE( list.empty() );


        int i { 0 };
        for( auto it = list.cbegin() ; it != list.cend() ; ++i )
            EXPECT_EQ( i+1, *it++ );
    }   
     
    {
        BEGIN_TEST(tm,"RangeConstructor", "checking constructors with a range of values");
        // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2( list.begin(), list.end() );
        
        EXPECT_EQ( list2.size(), 5 );
        EXPECT_FALSE( list.empty() );

        // recover elements to test
        auto i{1};
        for( auto e : list2)
            EXPECT_EQ( e, i++ );

        // Copy only part of the original range.
        which_lib::list<int> list3( std::next( list.begin(), 1 ), std::next( list.begin(), 3 ) );
        EXPECT_EQ( list3.size(), 2 );
        EXPECT_FALSE( list3.empty() );

        auto it2 = std::next( list.begin(), 1 );
        for (auto it = list3.begin() ; it != list3.end() ; ++it, ++it2 )
            EXPECT_EQ( *it, *it2 );
    }
    
    {
        BEGIN_TEST(tm, "CopyConstructor","constructor copy values of another list.");
            // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2( list );

        EXPECT_EQ( list2.size(), 5 );
        EXPECT_FALSE( list2.empty() );

        // recover elements to test.

        auto i{1};
        for( auto e : list2 )
            EXPECT_EQ( e, i++ );

        // Changing seq (the original)...
        auto it = std::next( list.begin(), 2 );
        *it = 10;
        // ... should not alter the copy.
        i = 1;
        for( auto e : list2 )
            EXPECT_EQ( e, i++ );
    }
#ifdef MOVE_SYNTAX_IMPLEMENTED

    // {
    //     BEGIN_TEST(tm, "Molistonstructor", "move the elements from another");
    //     // Range = the entire list.
    //     which_lib::list<int> list{ 1, 2, 3, 4, 5 };
    //     which_lib::list<int> list2( std::move( list ) );
        
    //     EXPECT_EQ( list2.size(), 5 );
    //     // EXPECT_FALSE( list2.empty() );

    //     // CHeck whether the copy worked.
    //     for( auto i{0u} ; i < list2.size() ; ++i )
    //         EXPECT_EQ( i+1, list2[i] );
    // }
#endif


    {
        BEGIN_TEST(tm, "AssignOperator", "ASSIGN OPERATOR");
        // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2;

        list2 = list;
        EXPECT_EQ( list2.size(), 5 );
        EXPECT_FALSE( list2.empty() );

        // recover elements to test.
        auto i{1};
        for( auto e : list2 )
            EXPECT_EQ ( e,i++ );;
    }

 #ifdef MOVE_SYNTAX_IMPLEMENTED  
    // // {
    // //     BEGIN_TEST(tm, "MoveAssignOperator", "MoveAssignOperator");
    // //     // Range = the entire list.
    // //     which_lib::list<int> list{ 1, 2, 3, 4, 5 };
    // //     which_lib::list<int> list2;

    // //     list2 = std::move( list );
    // //     EXPECT_EQ( list2.size(), 5 );
    // //     EXPECT_FALSE( list2.empty() );
    // //     EXPECT_EQ( list.size(), 0 );
    // //     EXPECT_EQ( list.capacity(), 0 );
    // //     EXPECT_TRUE( list.empty() );

    // //     // CHeck whether the copy worked.
    // //     for( auto i{0u} ; i < list2.size() ; ++i )
    // //         EXPECT_EQ( i+1, list2[i] );
    // // }
#endif


    {
        BEGIN_TEST(tm, "ListInitializerAssign","initializer list assignment");
        // Range = the entire list.
        which_lib::list<int> list = { 1, 2, 3, 4, 5 };

        EXPECT_EQ( list.size(), 5 );
        EXPECT_FALSE( list.empty() );

        // recover elements to test.
        auto i{1};
        for( auto e : list )
            EXPECT_EQ ( e, i++ );
    }


    {
        BEGIN_TEST(tm, "Clear", "clear");
        // Range = the entire list.
        which_lib::list<int> list = { 1, 2, 3, 4, 5 };

        EXPECT_EQ( list.size(), 5 );
        EXPECT_FALSE( list.empty() );

        list.clear();

        EXPECT_EQ( list.size(), 0 );
        EXPECT_TRUE( list.empty() );
    }

    {
        BEGIN_TEST(tm, "PushFront","PushFront");
        // #1 From an empty list.
        which_lib::list<int> list;

        EXPECT_TRUE( list.empty() );
        for ( auto i{0} ; i < 5 ; ++i )
        {
            list.push_front( i+1 );
            EXPECT_EQ( list.size(),  i+1 );
        }
        EXPECT_FALSE( list.empty() );

        auto i{5};
        for ( const auto & e: list )
            EXPECT_EQ( e , i-- );


        // REmove all elements.
        list.clear();
        EXPECT_TRUE(list.empty()  );
        for ( auto i{0u} ; i < 5 ; ++i )
        {
            list.push_front( i+1 );
            EXPECT_EQ( list.size(),  i+1 );
        }
        EXPECT_FALSE( list.empty() );

        i = 5;
        for ( const auto & e: list )
        {
            EXPECT_EQ( e , i-- );
        }
            
    }


    {
        BEGIN_TEST(tm, "PushBack", "PushBack");
        // #1 From an empty list.
        which_lib::list<int> list;

        EXPECT_TRUE( list.empty() );
        for ( auto i{0} ; i < 5 ; ++i )
        {
            list.push_back( i+1 );
            EXPECT_EQ( list.size(),  i+1 );
        }
        EXPECT_FALSE( list.empty() );

        auto i{0};
        for ( const auto & e: list )
            EXPECT_EQ( e , ++i );

        // REmove all elements.
        list.clear();
        EXPECT_TRUE( list.empty()  );
        for ( auto i{0} ; i < 5 ; ++i )
        {
            list.push_back( i+1 );
            EXPECT_EQ( list.size(),  i+1 );
        }
        EXPECT_FALSE( list.empty() );
        
        i=0;
        for ( const auto & e: list )
            EXPECT_EQ( e , ++i );
    }

    {
        BEGIN_TEST(tm, "PopBack", "PopBack");
        // #1 From an empty list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };

        while( not list.empty() )
        {
            list.pop_back();
            // Checke whether we have the same list except for the last.
            auto i {0};
            for ( const auto & e: list )
                EXPECT_EQ( e , ++i );
        }
    }
    
    {
        BEGIN_TEST(tm, "PopFront", "PopFront");
        // #1 From an empty list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };

        auto start{1};
        while( not list.empty() )
        {
            list.pop_front();
            // Checke whether we have the same list except for the last.
            auto i {start};
            for ( const auto & e: list )
                EXPECT_EQ( e, ++i );
            start++;
        }
    }


    {
        BEGIN_TEST(tm, "Front", "front");
        // #1 From an empty list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };

        auto i{0};
        while( not list.empty() )
        {
            auto current_size = list.size();
            EXPECT_EQ( list.front(), ++i );
            EXPECT_EQ( current_size, list.size() );
            list.pop_front();
        }
    }

    {
        BEGIN_TEST(tm, "FrontConst","FrontConst");
        // #1 From an empty list.
        const which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        EXPECT_EQ( list.front(), 1 );

        const which_lib::list<char> list2{ 'a', 'e', 'i', 'o', 'u' };
        EXPECT_EQ( list2.front(), 'a' );
    }


    {
        BEGIN_TEST(tm, "Back","Back");
        // #1 From an empty list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
    
        auto i{5};
        while( not list.empty() )
        {
            auto current_size = list.size();
            EXPECT_EQ( list.back(), i-- );
            EXPECT_EQ( current_size, list.size() );
            list.pop_back();
        }
    }
    
    
    {
        BEGIN_TEST(tm, "BackConst","BackConst");
        // #1 From an empty list.
        const which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        EXPECT_EQ( list.back(), 5 );
    
        const which_lib::list<char> list2{ 'a', 'e', 'i', 'o', 'u' };
        EXPECT_EQ( list2.back(), 'u' );
    }

    
    
    // {
    //     BEGIN_TEST(tm, "AssignCountValue","AssignCountValue");
    //     // #1 From an empty list.
    //     which_lib::list<long> list{ 1, 2, 3, 4, 5 };
    
    //     EXPECT_EQ( list.size(), 5 );
            
    //     // Test assign with a count smaller than the original list size.
    //     long value{-4};
    //     list.assign( 3, value );
    //     EXPECT_EQ( list.size(), 3 );
    //     // Capacity should be the same.
    //     // EXPECT_EQ( list.capacity(), original_cap );
    //     // Verify the elements.
    //     for ( auto i{0u} ; i < list.size() ; ++i )
    //         EXPECT_EQ( value, list[i] );
    
    //     // Test assign with a count GREATER than the original list size.
    //     long new_value{42};
    //     list.assign( 10, new_value );
    //     EXPECT_EQ( list.size(), 10 );
    //     EXPECT_GE( list.capacity(), original_cap );
    //     // Verify the elements.
    //     for ( auto i{0u} ; i < list.size() ; ++i )
    //         EXPECT_EQ( new_value, list[i] );
    // }
    
    
    {
        BEGIN_TEST(tm, "OperatorEqual","OperatorEqual");
        // #1 From an empty list.
        which_lib::list<int> list { 1, 2, 3, 4, 5 };
        which_lib::list<int> list2 { 1, 2, 3, 4, 5 };
        which_lib::list<int> list3 { 1, 2, 8, 4, 5 };
        which_lib::list<int> list4 { 8, 4, 5 };
    
        EXPECT_EQ( list , list2 );
        EXPECT_TRUE( not ( list == list3 ) );
        EXPECT_TRUE( not ( list == list4 ) );
    }
    
    
    {
        BEGIN_TEST(tm, "OperatorDifferent","OperatorDifferent");
        // #1 From an empty list.
        which_lib::list<int> list { 1, 2, 3, 4, 5 };
        which_lib::list<int> list2 { 1, 2, 3, 4, 5 };
        which_lib::list<int> list3 { 1, 2, 8, 4, 5 };
        which_lib::list<int> list4 { 8, 4, 5 };
    
        EXPECT_TRUE( not( list != list2 ) );
        EXPECT_NE( list, list3 );
        EXPECT_NE( list,list4 );
    }
    
    
    {
        BEGIN_TEST(tm, "InsertSingleValueAtPosition","InsertSingleValueAtPosition");
        // #1 From an empty list.
        which_lib::list<int> list { 1, 2, 4, 5, 6 };
    
        // Insert at front
        list.insert( list.begin(), 0 );
        EXPECT_EQ( list , ( which_lib::list<int>{ 0, 1, 2, 4, 5, 6 } ) );

        // Insert in the middle
        list.insert( std::next(list.begin(),3), 3 );
        EXPECT_EQ( list , ( which_lib::list<int>{ 0, 1, 2, 3, 4, 5, 6 } ) );

        // Insert at the end
        list.insert( list.end(), 7 );
        EXPECT_EQ( list , ( which_lib::list<int>{ 0, 1, 2, 3, 4, 5, 6, 7 } ) );

    }
    
    
    {
        BEGIN_TEST(tm, "InsertRange","InsertRange");
        // Aux arrays.
        which_lib::list<int> list1 { 1, 2, 3, 4, 5 };
        which_lib::list<int> list2 { 1, 2, 3, 4, 5 };
        which_lib::list<int> source { 6, 7, 8, 9, 10 };
    
        // Inset at the begining.
        list1.insert( list1.begin(), source.begin(), source.end() );
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 } ) );

        // In the middle
        list1 = list2;
        list1.insert( std::next( list1.begin(), 2 ), source.begin(), source.end() );
    
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 6, 7, 8, 9, 10, 3, 4, 5 } ) );
    
        // At the end
        list1 = list2;
        list1.insert( list1.end(), source.begin(), source.end() );
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) );

        // // Outside
        // list1 = list2;
        // list1.insert( std::next( list1.end(), 2 ) , source.begin(), source.end() );
        // EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 3, 4, 5 } ) );
    
    }
    
    
    {
        BEGIN_TEST(tm, "InsertInitializarList","InsertInitializarList");
        // Aux arrays.
        which_lib::list<int> list1 { 1, 2, 3, 4, 5 };
        which_lib::list<int> list2 { 1, 2, 3, 4, 5 };
        which_lib::list<int> source { 6, 7, 8, 9, 10 };
    
        // Inset at the begining.
        list1.insert( list1.begin(), { 6, 7, 8, 9, 10 } );
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 } ) );
       
        // In the middle
        list1 = list2;
        list1.insert( std::next( list1.begin(), 2 ), { 6, 7, 8, 9, 10 } );
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 6, 7, 8, 9, 10, 3, 4, 5 } ) );
    
        // At the end
        list1 = list2;
        list1.insert( list1.end(), { 6, 7, 8, 9, 10 } );
        EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) );

        // // Outside
        // list1 = list2;
        // list1.insert( std::next( list1.end(), 2 ) , { 6, 7, 8, 9, 10 } );
        // EXPECT_EQ( list1 , ( which_lib::list<int>{ 1, 2, 3, 4, 5 } ) );
    }
    
    
    // // {
    // //     BEGIN_TEST(tm, "AssignCountValue2","AssignCountValue2");
    // //     // Initial list.
    // //     which_lib::list<char> list { 'a', 'b', 'c', 'd', 'e' };
    
    // //     // assigning count values to which_lib::list, with count < size().
    // //     list.assign( 3, 'x' );
    // //     which_lib::list<char> list2 { 'x', 'x', 'x' };
    // //     //ASSERT_EQ( list , ( which_lib::list<char>{ 'x', 'x', 'x' } ) );
    // //     EXPECT_EQ( list , list2 );
    // //     EXPECT_EQ( list.size() , 3 );
    // //     EXPECT_EQ( list.capacity() , 5 );
    
    // //     // assigning count values to which_lib::list, with count , size().
    // //     list = { 'a', 'b', 'c', 'd', 'e' };
    // //     list.assign( 5, 'y' );
    // //     EXPECT_EQ( list , ( which_lib::list<char>{ 'y','y','y','y','y' } ) );
    // //     EXPECT_EQ( list.size() , 5 );
    // //     EXPECT_EQ( list.capacity() , 5 );
    
    // //     // assigning count values to which_lib::list, with count > size().
    // //     list = { 'a', 'b', 'c', 'd', 'e' };
    // //     list.assign( 8, 'z' );
    // //     EXPECT_EQ( list , ( which_lib::list<char>{ 'z','z','z','z','z','z','z','z' } ) );
    // //     EXPECT_EQ( list.size() , 8 );
    // //     EXPECT_EQ( list.capacity() , 8 );
    // // }
    
    
    {
        BEGIN_TEST(tm, "EraseRange","EraseRange");
        // Initial list.
        which_lib::list<int> list { 1, 2, 3, 4, 5 };
    
        // removing a segment from the beginning.
        auto past_last = list.erase( list.begin(), std::next(list.begin(),3) );
        EXPECT_EQ( list.begin() , past_last );
        EXPECT_EQ( list , ( which_lib::list<int>{ 4, 5 } ) );
        EXPECT_EQ( list.size() , 2 );
    
        // removing at the middle.
        list = { 1, 2, 3, 4, 5 };
        past_last = list.erase( std::next(list.begin(),1), std::next(list.begin(),4) );
        EXPECT_EQ( std::next(list.begin(),1) , past_last );
        EXPECT_EQ( list , ( which_lib::list<int>{ 1, 5 } ) );
        EXPECT_EQ( list.size() , 2 );
    
        // removing a segment that reached the end.
        list = { 1, 2, 3, 4, 5 };
        past_last = list.erase( std::next(list.begin(),2), list.end() );
        EXPECT_EQ( list.end() , past_last );
    
        EXPECT_EQ( list , ( which_lib::list<int>{ 1, 2 } ) );
        EXPECT_EQ( list.size() , 2 );
        // removing the entire list.
        list = { 1, 2, 3, 4, 5 };
        past_last = list.erase( list.begin(), list.end() );
        EXPECT_EQ( list.end() , past_last );
        EXPECT_TRUE( list.empty() );
    }
    
    
    {
        BEGIN_TEST(tm, "ErasePos","ErasePos");
        // Initial list.
        which_lib::list<int> list { 1, 2, 3, 4, 5 };
    
        // removing a single element.
        list = { 1, 2, 3, 4, 5 };
        auto past_last = list.erase( list.begin() );
        EXPECT_EQ( list , ( which_lib::list<int>{ 2, 3, 4, 5 } ) );
        EXPECT_EQ( list.begin() , past_last );
        EXPECT_EQ( list.size() , 4 );
    
        // removing a single element in the middle.
        list = { 1, 2, 3, 4, 5 };

        past_last = list.erase( std::next(list.begin(),2) );
        EXPECT_EQ( list , ( which_lib::list<int>{ 1, 2, 4, 5 } ) );

        std::cout << " \n";
        EXPECT_EQ( std::next(list.begin(),2) , past_last );
        EXPECT_EQ( list.size() , 4 );
    
        // removing a single element at the end.
        list = { 1, 2, 3, 4, 5 };
        past_last = list.erase( std::next(list.begin(),list.size()-1 ) );
        EXPECT_EQ( list , ( which_lib::list<int>{ 1, 2, 3, 4 } ) );
        EXPECT_EQ( list.end() , past_last );
        EXPECT_EQ( list.size() , 4 );
    }

        tm.summary();
        return 0;
    }
    