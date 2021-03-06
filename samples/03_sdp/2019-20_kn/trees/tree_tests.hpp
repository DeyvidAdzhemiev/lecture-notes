TEST_CASE("Create Empty Tree")
{
    BinTree<int> empty;
}

#include <fstream>

TEST_CASE("Create Non-Empty Tree")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    /**************************************
    **    КОМАНДЕН РЕД ЗА GRAPHVIZ       **
    **                                   **
    ** >dot tree.dot -Tpdf -o tree.pdf   **
    **                                   **
    **************************************/
   
    std::ofstream file ("tree.dot");
    test.dottyPrint(file);
}

TEST_CASE("Member Test")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (test.member(7)==true);
    CHECK (test.member(30)==true);
    CHECK (test.member(12)==true);
    CHECK (test.member(90)==true);
    CHECK (test.member(5)==true);
    CHECK (test.member(50)==true);
    CHECK (test.member(8)==false);
    CHECK (test.member(18)==false);
    CHECK (test.member(51)==false);
    CHECK (test.member(9)==false);
    CHECK (test.member(0)==false);
    CHECK (test.member(-1)==false);

}

TEST_CASE("Test Sum")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (sumElements(test.rootPos()) == 194);

}

int plus (const int& x, const int& y)
{
    return x+y;
}

TEST_CASE("Test Reduce")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    CHECK (test.reduce(plus,0) == sumElements(test.rootPos()));

}

TEST_CASE("Test Copy and Delete")
{
    BinTree<int> *test = new BinTree<int>;

    test->addElement ("",7);
    test->addElement ("L",30);
    test->addElement ("LR",12);
    test->addElement ("LRL",90);
    test->addElement ("R",5);
    test->addElement ("RL",50);

    BinTree<int> *copy  = new BinTree<int> (*test);

    CHECK (sumElements(test->rootPos()) == 
           sumElements (copy->rootPos()));
    CHECK (sumElements(test->rootPos().left()) == 
           sumElements (copy->rootPos().left()));

    test->addElement ("LL",100);
    CHECK (sumElements(test->rootPos()) == 
           sumElements (copy->rootPos())+100);

    delete test;
    CHECK (sumElements (copy->rootPos())==194);
    delete copy;

}

TEST_CASE("Test Assignment")
{
    BinTree<int> test;

    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);

    BinTree<int> copy;
    
    copy = test;

    CHECK (sumElements(test.rootPos()) == 
           sumElements (copy.rootPos()));
    CHECK (sumElements(test.rootPos().left()) == 
           sumElements (copy.rootPos().left()));

    test.addElement ("LL",100);
    CHECK (sumElements(test.rootPos()) == 
           sumElements (copy.rootPos())+100);


}

TEST_CASE("Test Tree Iter")
{
    BOTree<int> bot;

    bot.insert (100)
       .insert (50)
       .insert (200)
       .insert (150)
       .insert (22332)
       .insert (24)
       .insert (75)
       .insert (8821)
       .insert (175);

    /*
    for (Interator it = bot.begin(); it != bot.end(); )
    {
        std::cout << *it;
        ++it;
    }
    */

   for (int x : bot)
    {
        std::cout << x << " ";
    }


}

TEST_CASE("Test Tree Iter Const")
{
    BOTree<int> bot;

    bot.insert (100)
       .insert (50)
       .insert (200)
       .insert (150)
       .insert (22332)
       .insert (24)
       .insert (75)
       .insert (8821)
       .insert (175);

    
    const BOTree<int> cbot = bot;

   for (int x : cbot)
    {
        std::cout << x << " ";
    }


}

