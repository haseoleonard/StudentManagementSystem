//
template <class T>
ArrayList<T>::ArrayList()
{
    _listSize = 2;
    _size = 0;
    _list = new T *[_listSize];
}
//
template <class T>
bool ArrayList<T>::isValidIndex(int index)
{
    return index >= 0 && index < _size;
}
//
template <class T>
bool ArrayList<T>::needExpansion()
{
    return _size >= _listSize;
}
//
template <class T>
void ArrayList<T>::expandArray()
{
    _listSize += (int)_listSize / 2;
    T **newList = new T *[_listSize];
    for (int i = 0; i < _size; i++)
    {
        newList[i] = _list[i];
    }
    delete[] _list;
    _list = newList;
}
//
template <class T>
bool ArrayList<T>::add(const T &object)
{
    if (needExpansion())
    {
        expandArray();
    }
    _list[_size] = new T(object);
    _size++;
    return true;
}

template <class T>
T *ArrayList<T>::removeAt(int index)
{
    if (isValidIndex(index))
    {
        T *removeItem = new T;
        removeItem = _list[index];
        for (int i = index + 1; i < _size; i++)
        {
            _list[i - 1] = _list[i];
        }
        _list[_size--] = nullptr;
        return removeItem;
    }
    else
    {
        throw std::out_of_range("Array Index Out Of Range");
    }
}

template <class T>
void ArrayList<T>::clear()
{
    _size = 0;
    _listSize = 2;
    delete[] _list;
    _list = new T*[_listSize];
}

template <class T>
T *ArrayList<T>::get(int index)
{
    if (isValidIndex(index))
    {
        T **requestedItem = new T *;
        *requestedItem = _list[index];
        return *requestedItem;
    }
    else
    {
        return nullptr;
    }
}
