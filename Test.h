#include <iostream>
#include <fstream>
#include "Header.h"
#include "FilesCmp.h"

using namespace std;

class FishTest : public ::testing::Test {	
};

TEST_F(FishTest, CheckZeroLength) 
{
	fish f;
	strcpy_s(f.name,"");
	int expected = 0;
	ASSERT_EQ(expected, f.LengthOfName());
}

TEST_F(FishTest, CheckLength) 
{
	fish f;
	strcpy_s(f.name, "Okun");
	int expected = 4;
	ASSERT_EQ(expected, f.LengthOfName());
}

TEST_F(FishTest, CheckInput) 
{
	ifstream ifst("InFish.txt");
	fish actual;
	actual.InData(ifst);
	fish f;
	strcpy_s(f.name, "Okun");
	f.age = 4;
	f.h = fish::habitat::RIVER;
	
	ASSERT_STREQ(actual.name, f.name);
	ASSERT_EQ(actual.age, f.age);
	ASSERT_EQ(actual.h, f.h);
}

TEST_F(FishTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	fish f;
	strcpy_s(f.name, "Okun");
	f.age = 4;
	f.h = fish::habitat::RIVER;
	f.Out(ofst);
	ofst.close();
	
	ifstream expected("OutFish.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


//##########################################################################################################
//##########################################################################################################

class BirdTest : public ::testing::Test {
};

TEST_F(BirdTest, CheckZeroLength) 
{
	bird b;
	strcpy_s(b.name, "");
	int expected = 0;
	ASSERT_EQ(expected, b.LengthOfName());
}

TEST_F(BirdTest, CheckLength)
{
	bird b;
	strcpy_s(b.name, "Sinica");
	int expected = 6;
	ASSERT_EQ(expected, b.LengthOfName());
}


TEST_F(BirdTest, CheckInput) 
{
	ifstream ifst("InBird.txt");
	bird actual;
	actual.InData(ifst);
	bird b;
	strcpy_s(b.name, "Sinica");
	b.age = 4;
	b.migratory = false;

	ASSERT_STREQ(actual.name, b.name);
	ASSERT_EQ(actual.age, b.age);
	ASSERT_EQ(actual.migratory, b.migratory);
}

TEST_F(BirdTest, CheckOutput) 
{
	ofstream ofst("OutTest.txt");
	bird b;
	strcpy_s(b.name, "Sinica");
	b.age = 4;
	b.migratory = false;
	b.Out(ofst);
	ofst.close();

	ifstream expected("OutBird.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

class BeastTest : public ::testing::Test {
};

TEST_F(BeastTest, CheckZeroLength) 
{
	beast be;
	strcpy_s(be.name, "");
	int expected = 0;
	ASSERT_EQ(expected, be.LengthOfName());
}

TEST_F(BeastTest, CheckLength)
{
	beast be;
	strcpy_s(be.name, "Tiger");
	int expected = 5;
	ASSERT_EQ(expected, be.LengthOfName());
}

TEST_F(BeastTest, CheckInput) 
{
	ifstream ifst("InBeast.txt");
	beast actual;
	actual.InData(ifst);
	beast be;
	strcpy_s(be.name, "Tiger");
	be.age = 4;
	be.t = beast::type::PREDATOR;

	ASSERT_STREQ(actual.name, be.name);
	ASSERT_EQ(actual.age, be.age);
	ASSERT_EQ(actual.t, be.t);
}

TEST_F(BeastTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	beast be;
	strcpy_s(be.name, "Tiger");
	be.age = 4;
	be.t = beast::type::PREDATOR;
	be.Out(ofst);
	ofst.close();

	ifstream expected("OutBeast.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

class AnimalTest : public ::testing::Test {
};

TEST_F(AnimalTest, CheckInputFish) 
{
	ifstream ifst("AnimalInFish.txt");
	animal *actual = animal::In(ifst);

	fish expected;
	strcpy_s(expected.name,"Okun");
	expected.age = 4;

	ASSERT_STREQ(expected.name, actual->name);
	ASSERT_EQ(expected.age, actual->age);
}

TEST_F(AnimalTest, CheckInputBird) 
{
	ifstream ifst("AnimalInBird.txt");
	animal *actual = animal::In(ifst);

	bird expected;
	strcpy_s(expected.name, "Sinica");
	expected.age = 4;

	ASSERT_STREQ(expected.name, actual->name);
	ASSERT_EQ(expected.age, actual->age);
}

TEST_F(AnimalTest, CheckInputBeast) 
{
	ifstream ifst("AnimalInBeast.txt");
	animal *actual = animal::In(ifst);

	beast expected;
	strcpy_s(expected.name, "Tiger");
	expected.age = 4;

	ASSERT_STREQ(expected.name, actual->name);
	ASSERT_EQ(expected.age, actual->age);
}

TEST_F(AnimalTest, CheckCompare) 
{
	fish a1;
	strcpy_s(a1.name, "Okun");

	fish a2;
	strcpy_s(a2.name, "Shark");

	ASSERT_TRUE(a1.Compare(a2));
}

//#############################################################################################
//#############################################################################################

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckInitContainer) 
{
	container c;

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearEmptyContainer) 
{

	container c;
	c.Clear();

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckClearContainer)
{

	container c;
	c.len = 0;
	animal* f = new fish;
	c.cont[c.len] = f;
	++c.len;
	c.Clear();

	ASSERT_EQ(c.len, 0);
}

TEST_F(ContainerTest, CheckOutFish) 
{
	ofstream ofst("OutTest.txt");

	container c;
	
	animal *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal *b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	c.cont[c.len] = b;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	c.cont[c.len] = (animal *)be;
	++c.len;

	c.OutFish(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutFish.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBird)
{
	ofstream ofst("OutTest.txt");

	container c;

	animal *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal *b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	c.cont[c.len] = b;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	c.cont[c.len] = (animal *)be;
	++c.len;

	c.OutBird(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBird.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBeast) 
{
	ofstream ofst("OutTest.txt");

	container c;

	animal *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal *b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	c.cont[c.len] = b;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	c.cont[c.len] = (animal *)be;
	++c.len;

	c.OutBeast(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBeast.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort)
{
	ofstream ofst("OutTest.txt");

	container c;

	animal *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal *b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	c.cont[c.len] = b;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	c.cont[c.len] = (animal *)be;
	++c.len;

	c.Sort(0);
	c.Out(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSort.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty)
{
	ofstream ofst("OutTest.txt");

	container c;

	c.Sort(0);
	c.Out(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEqual)
{
	ofstream ofst("OutTest.txt");

	container c;

	animal* f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Lion");
	be->age = 4;
	c.cont[c.len] = be;
	++c.len;

	c.Sort(0);
	c.Out(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOut) 
{
	ofstream ofst("OutTest.txt");

	container c;

	animal *f = new fish;
	strcpy_s(f->name, "Okun");
	f->age = 4;
	c.cont[c.len] = f;
	++c.len;

	animal *b = new bird;
	strcpy_s(b->name, "Sinica");
	b->age = 4;
	c.cont[c.len] = b;
	++c.len;

	animal* be = new beast;
	strcpy_s(be->name, "Tiger");
	be->age = 4;
	c.cont[c.len] = (animal *)be;
	++c.len;

	c.Out(ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOut.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
