#ifndef CONTAINER_H
#define CONTAINER_H

#include <map>
#include <string>
#include <sstream>
#include "dictionary.h"

template<class TKey>
class NotFoundKeyException :public NotFoundException<TKey>
{
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
private:
	TKey key;
	std::string message;
};

template<class TKey, class TValue>
class Container :public Dictionary<TKey, TValue>
{
public:
	const TValue& Get(const TKey& key) const
	{
		const auto found = this->store.find(key);
		if (found == this->store.cend())
			throw NotFoundKeyException<TKey>(key);
		return found->second;
	}

	void Set(const TKey& key, const TValue& value)
	{
		this->store[key] = value;
	}

	bool IsSet(const TKey& key) const
	{
		return this->store.count(key);
	}

	~Container()
	{
		delete this;
	}
private:
	std::map<TKey, TValue> store;
};

#endif
