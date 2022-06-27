#if defined VERTEX_PROGRAM

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

uniform mat4 k_worldViewProj;

void main()
{
	gl_Position = k_worldViewProj * vec4( vertexPosition, 1 );
	UV = vertexUV;
}

#elif defined FRAGMENT_PROGRAM

in vec2 UV;

out vec4 colour;

uniform sampler2D k_sampler0;

void main()
{
	colour = texture( k_sampler0, UV );
	float g = sqrt( dot( colour * colour, vec4( 0.299, 0.587, 0.114, 0.000 ) ) );
	g = min( g, 0.8 );
	colour = vec4( g );
}

#endif