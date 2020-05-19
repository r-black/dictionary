#ifndef CONTAINER_H
#define CONTAINER_H

#include <map>
#include <string>
#include <sstream>
#include "dictionary.h"

template<class TKey>
class NotFoundKeyException :public NotFoundException<TKey>
{
	TKey key;
	std::string message;
public:

	NotFoundKeyException(const TKey& k)
	{
		this->key = k;
		std::ostringstream ostr;
		ostr << "Key \"" << this->key << "\" not found";
		this->message = ostr.str();
	}

	virtual ~NotFoundKeyException() throw() {}

	virtual const char* what() const throw()
	{
		return this->message.c_str();
	}

	const TKey& GetKey() const noexcept override
	{
		return this->key;
	}
};

template<class TKey, class TValue>
class Container :public Dictionary<TKey, TValue>
{
	std::map<TKey, TValue> store;
public:

	const TValue& Get(const TKey& key) const
	{
		const auto found = store.find(key);
		if (found == store.cend())
			throw NotFoundKeyException<TKey>(key);
		return found->second;
	}

	void Set(const TKey& key, const TValue& value)
	{
		store[key] = value;
	}

	bool IsSet(const TKey& key) const
	{
		return store.count(key);
	}
};

#endif
