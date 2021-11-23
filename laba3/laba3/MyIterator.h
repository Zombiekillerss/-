#pragma once

class MyIterator
{
public:
	virtual ~MyIterator() {};
	virtual bool has_next() = 0;
	virtual int next() = 0;
};