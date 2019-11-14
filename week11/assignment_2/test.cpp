#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

int main() {
    {
        Number* a = new Integer(13);
        Number* result = a->add(new Float(3.14));

        std::cout << dynamic_cast<Float *>(result)->val() << std::endl;
    }
    {
        Number* a = new Integer(3);
        Number* result = a
                ->add(new Float(3.14))
                ->sub(new Integer(1))
                ->mul(new Integer(7))
                ->sub(new Complex(11, 5));

        std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl;
    }
	{
		Number* a(new Complex(12.4, 13.5));
		Number* result = a
				->add(new Integer(2))
				->sub(new Complex(3.4, 3.5))
				->mul(new Float(2.0))
				->div(new Integer(0));
		std::cout << dynamic_cast<Complex*>(result)->to_string() << std::endl;
	}

    return 0;
}
