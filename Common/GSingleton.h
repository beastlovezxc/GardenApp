#ifndef _GSINGLETON_H_
#define _GSINGLETON_H_

/**
 * This class (a) defines an Instance operation that lets clients access its
 * unique instance, and (b) may be responsible for creating its own unique
 * instance.
 */
extern "C" {
    #include "GBasicType.h"
}

template<class T>
class GSingleton
{
public:
	static T * instance()
	{
		if(m_instance == NULL)
			m_instance	=	new T();

		return m_instance;
	}

    virtual ~GSingleton() {

    }

protected:
    GSingleton() {

	}

private:
	static T * m_instance;

};

template<class T>
T * GSingleton<T>::m_instance = NULL;
#endif
