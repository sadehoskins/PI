#ifndef MY_CPP_ARRAY_H_
#define MY_CPP_ARRAY_H_

// Dynamic array class -> support integer storage
// size tracking, min/max queries, value search by index
class MyCppArray {
	public:
	MyCppArray();

	// dynamic memory managment
	~MyCppArray();
	MyCppArray(const MyCppArray& other);
	MyCppArray& operator=(const MyCppArray& other);

	void Insert(int value);

	// part b: dynamic resizing
	void Init(int length);

	int size() const;
	int min() const;
	int max() const;
	int Find(int value) const;
	bool empty() const;

private:
	static const int kMaxCapacity = 100;

	int* data_;
	int size_;
	int capacity_;
	bool dynamic_;
	int fixed_data_[kMaxCapacity];
};

#endif	// MY_CPP_ARRAY_H_
