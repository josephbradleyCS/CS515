
// Below are the stubs for SOME methods
// Make sure all methods in unorderedmap.h are implemented

template <typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::rehash( ){

  int tempArraySize = nextPrime(tablesize * 2);
  Entry ** tempArray = new Entry * [tempArraySize] {nullptr};

  for (int i = 0; i < tablesize; i++) {
    if (array[i] != nullptr) {
      Entry * p = array[i];
      while (p != nullptr) {
        Entry * newEntry = new Entry(p->key, p->data);
        std::size_t key = H()(p->key);
        key = key % tempArraySize;
        if (tempArray[key] == nullptr) {
          tempArray[key] = newEntry;
        } else {
          Entry * alreadyThere = tempArray[key];
          tempArray[key] = newEntry;
          newEntry->next = alreadyThere;
        }
        p = p->next;
      }
    }
  }

  int en = entrysize;
  destructCode();
  entrysize = en;
  array = tempArray;
  tablesize = tempArraySize;
}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(){
  tablesize = 101;
  entrysize = 0;
  array = new Entry*[101] {nullptr};



}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(const UnorderedMap& rhs) {
  destructCode();
  copyCode(rhs);
}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>& UnorderedMap<KEY, T, H>::operator=(const UnorderedMap& rhs) {
  destructCode();
  copyCode(rhs);
  return *this;
}

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::~UnorderedMap(){
  destructCode();
  tablesize = 0;
  entrysize = 0;
}

template <typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::destructCode(){
	for (int i = 0; i < tablesize; i++) {
    while (array[i] != nullptr) {
      Entry * a = array[i];
      array[i] = a->next;
      delete a;
    }
  }

  delete [] array;

}

template <typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::copyCode(const UnorderedMap& rhs) {
  array = new Entry*[rhs.tablesize];
  entrysize = rhs.entrysize;
  for (int i = 0; i < tablesize; i++) {
    if (rhs.array[i] == nullptr) {
      array[i] = nullptr;
    } else {
      array[i] = rhs.array[i];

      Entry * newEnt = rhs.array[i];
      Entry * oldEnt = array[i];

      while (newEnt->next != nullptr) {
        oldEnt->next = newEnt->next;
        newEnt = newEnt->next;
        oldEnt = oldEnt->next;
      }
    }
  }
	return;
}

//Iterator

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Entry& UnorderedMap<KEY, T, H>::Iterator::operator*(){
	return *_cur;
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Entry* UnorderedMap<KEY, T, H>::Iterator::operator->(){
	return _cur;
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::Iterator::operator++(int a){
	if (_cur->next != nullptr) {
    _cur = _cur->next;
    return Iterator(_cur->next, map);
  }

  std::size_t key = H()(_cur->key);
  key = key % map->tablesize;
  key++;

  while (map->array[key] == nullptr) {
    key++;
    if (key >= map->tablesize) {
      _cur = nullptr;
      return Iterator(nullptr);
    }
  }

  _cur = map->array[key];

  Iterator i = *this;
  // if (a > 1) {
  //   i++(a-1);
  //   a--;
  // }

  return i;
}


template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::Iterator::operator!=(Iterator it){
	return _cur != it._cur;
}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::Iterator::operator==(Iterator it){
	return _cur == it._cur;
}

// End Iterator

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::begin() const{
	// stub code; need to implement !!!
  // if entry size == 0, the map is empty, return an iterator to our dummy end
  if (entrysize == 0) {return end();}

  // entrysize != 0, there is stuff in the map
	for (int i = 0; i < tablesize; i++) {
    // the first non null entry in the map is our begin
    if (array[i] != nullptr) {
      // returining an iterator to the first entry in the map
      return Iterator(array[i], this);
    }
  }

  // we got throught the whole map and eveything is null
  // returning and interator to our dummy end
  return end();
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::end() const {
  return Iterator(nullptr);
}



template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::insert(const KEY & newKey, const T & data){

  if (find(newKey) != end()) {return true;}

	std::size_t key = H()(newKey);
  key = key % tablesize;

  Entry * n = new Entry(newKey, data);

  if (array[key] == nullptr) {
    array[key] = n;
    array[key]->next = nullptr;
  } else {
    n->next = array[key];
    array[key] = n;
  }

  // if (entrysize/tablesize > 2) {
  //   rehash();
  // }

  entrysize++;
	return true;
}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::erase(const KEY & newKey){
	std::size_t key = H()(newKey);
  key = key % tablesize;

  Entry * a = array[key];

  if (a == nullptr) {
    return false;
  } else {
    if (a->key == newKey) {
      if (a->next == nullptr) {
        delete array[key];
        array[key] = nullptr;
      } else {
        array[key] = a->next;
        delete a;
      }
    } else {
      // itampArraySize in the chain
      while (a->next != nullptr) {
        if (a->next->key == newKey) {
          Entry * temp = a->next->next;
          delete a->next;
          a->next = temp;
          entrysize--;
          return true;
        }
        a = a->next;
      }
      // not there
      return false;
    }
  }
  entrysize--;
	return true;
}

template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::find( const KEY & x ) const{
  // if entrysize == 0, there is nothing to find, return end()
  if (entrysize == 0) {return Iterator(nullptr);}

  std::size_t key = H()(x);
  key = key % tablesize;
  Entry * a = array[key];

  // if the bucket is empty, return end()
  if (a == nullptr) {return Iterator(nullptr);}

  while (a) {
    if (a->key == x) {return Iterator(a, this);}
    a = a->next;
  }

  return Iterator(nullptr);
}



template<typename KEY, typename T, typename H>
T& UnorderedMap<KEY, T, H>::operator[](const KEY & k){

  Iterator it = find(k);
  if (it == end()) {
    static T tmp = T();
    insert(k, tmp);
    it = find(k);
  }

  return it->data;
}



template<typename KEY, typename T, typename H>
void UnorderedMap<KEY, T, H>::dump() {
  cout << "\ndump:::\n";
  for (int i = 0; i < tablesize; i++) {
    if (array[i] != nullptr) {
      Entry * a = array[i];
      cout << "Entry: (" << a->key << ", " << a->data << ") -> ";
      a = a->next;
      while (a) {
        cout << "(" << a->key << ", " << a->data << ") -> ";
        a = a->next;
      }
      cout << endl;
    }
  }
  cout << endl;
}





// Internal method to test if a positive number is prime (not efficient)
bool isPrime( int n ){
	if( n == 2 || n == 3 )
		return true;
	if( n == 1 || n % 2 == 0 )
		return false;
	for( int i = 3; i * i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

// Internal method to return a prime number at least as large as n.
// Assumes n > 0.
int nextPrime( int n ){
	if( n % 2 == 0 )
		n++;
	for( ; !isPrime( n ); n += 2 )
		;
	return n;
}
