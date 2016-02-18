#ifndef COLOR_H
#define COLOR_H

namespace rtrace
{
	class Color
	{
	public:
		int r;
		int g;
		int b;
		Color(int r_, int g_, int b_)
		{
			r = r_;
			g = g_;
			b = b_;
		}
	};
}

#endif