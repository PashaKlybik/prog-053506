#include "main.h"
#include <cassert>

int TestAlbum();
int TestComposition();
int TestArtist();
int TestAdd();

#undef main
int main()
{
    TestAlbum();
    TestComposition();
    TestArtist();
    TestAdd();
}

int TestComposition()
{
    Composition *test;
    assert((test = new Composition("testName", "artistTestName", 123, "testText")) != NULL);

    assert(test->getName() == "testName");
    assert(test->getPrice() == 123);
    assert(test->getArtistName() == "artistTestName");
    assert(test->getText() == "testText");

    return 0;
}

int TestAlbum()
{
    vector<Composition> compositions;

    Composition *testCom;
    assert((testCom = new Composition("testName", "artistTestName", 123, "testText")) != NULL);

    assert(testCom->getName() == "testName");
    assert(testCom->getPrice() == 123);
    assert(testCom->getArtistName() == "artistTestName");
    assert(testCom->getText() == "testText");

    compositions.push_back(*testCom);
    Album test("name", compositions);

    assert(test.getPrice() == 123);    
    assert(test.getName() == "name");

    return 0;
}

int TestArtist()
{   
    vector<Composition> compositions;

    Composition *testCom;
    assert((testCom = new Composition("testName", "artistTestName", 123, "testText")) != NULL);

    assert(testCom->getName() == "testName");
    assert(testCom->getPrice() == 123);
    assert(testCom->getArtistName() == "artistTestName");
    assert(testCom->getText() == "testText");

    compositions.push_back(*testCom);

    vector<Album> albums;

    Album testAlbum("testNAme", compositions);

    albums.push_back(testAlbum);

    Artist TestArtist(compositions, albums, "info");

    assert(TestArtist.getInfo() == "info");
    assert(TestArtist.getName() == "artistTestName");

    return 0;
}

int TestAdd()
{
    Mp3All mp;
	mp.addCompositions();
	mp.addAlbums();
	mp.addArtists();
	mp.addMusicalDirections();

    for (MusicalDirection tempMusicalDirection : mp.getAllMusicalDirections()) 
    {
        assert(tempMusicalDirection.getName() == "rock" || tempMusicalDirection.getName() == "qwe");
        assert(tempMusicalDirection.getInfo() == "fsdfdasfsdv\ndfsadf" || tempMusicalDirection.getInfo() == "ffwqwdq");
    }


    return 0;
}