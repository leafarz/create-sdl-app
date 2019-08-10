#include "MathUtil.h"
#include <limits>

namespace gg { namespace math {
	float sin(float deg)
	{
		return std::sinf(deg * DEG_TO_RAD);
	}

	float cos(float deg)
	{
		return std::cosf(deg * DEG_TO_RAD);
	}

	bool floatCmp(float a, float b, float threshold)
	{
		return std::abs(a - b) < threshold;
	}

	bool doubleCmp(double a, double b, float threshold)
	{
		return std::abs(a - b) < threshold;
	}

	float clamp(float val, float min, float max)
	{
		return (val < min) ? min : (val > max) ? max : val;
	}

	float lerp(float from, float to, float p)
	{
		return from + (to - from) * p;
	}

	double lerp(double from, double to, double p)
	{
		return (from + (to - from) * p);
	}
}/*namespace math*/ }// namespace gg
