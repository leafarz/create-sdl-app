#ifndef		AABB_H
#define		AABB_H
#pragma once

#include "Vec2f.h"

namespace gg { namespace math { struct Vec2f; } }
using namespace gg::math;

struct AABB
{
public:
	AABB(void);
	AABB(const Vec2f& center, const Vec2f& extent);

	const Vec2f& getCenter(void) const { return center; }
	const Vec2f& getExtents(void) const { return extents; }

	bool containsPoint(const Vec2f& position) const;
	bool intersects(const AABB& other) const;

private:
	Vec2f center;
	Vec2f extents;
};
#endif
