#ifndef COLOR_H
#define COLOR_H

#include <ostream>
#include <math.h>

namespace rtrace
{
	class Color
	{
	public:
		int r;
		int g;
		int b;
		Color()
		{
			r = 0;
			g = 0;
			b = 0;
		}

		Color(int r_, int g_, int b_)
		{
			r = r_;
			g = g_;
			b = b_;
		}

		Color(const Color& c)
		{
			r = c.r;
			g = c.g;
			b = c.b;
		}

		void set(int r_, int g_, int b_)
		{
			r = r_;
			g = g_;
			b = b_;
		}

		void set(Color c)
		{
			set(c.r,c.g,c.b);
		}

		Color operator=(const Color& c)
		{
			this->r = c.r;
			this->g = c.g;
			this->b = c.b;
			return *this;
		}

		Color operator+=(const Color& c)
		{
			this->r += c.r;
			this->g += c.g;
			this->b += c.b;
			return *this;
		}

		Color operator*(const double d)
		{
			Color n;
			n.r = (int)round(this->r * d);
			n.g = (int)round(this->g * d);
			n.b = (int)round(this->b * d);
			return n;
		}

		Color operator/(const double d) {

			Color n;
			n.r = (this->r / d);
			n.g = (int)round(this->g / d);
			n.b = (int)round(this->b / d);
			return n;
		}

		bool operator==(const Color& c)
		{
			return c.r==this->r && c.g==this->g && c.b==this->b;
		}

		friend std::ostream& operator<<(std::ostream& strm, const Color& c)
		{
			return strm << c.r << " " << c.g << " " << c.b;
		}
	};
}



#endif