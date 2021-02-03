#include "freeflycamera.h"

#include <cmath>
#include <GL/glu.h>
#include <iostream>

FreeFlyCamera::FreeFlyCamera(const Vector3D & position)
{
    _position = position;
    _phi = 0;
    _theta = 0;
    VectorsFromAngles();

    _speed = 0.01;
    _sensivity = 0.2;
    _verticalMotionActive = false;
    _keyconf["forward"] = SDLK_w;
    _keyconf["backward"] = SDLK_s;
    _keyconf["strafe_left"] = SDLK_a;
    _keyconf["strafe_right"] = SDLK_d;
    _keyconf["boost"] = SDLK_LSHIFT;
    _keystates[_keyconf["forward"]] = false;
    _keystates[_keyconf["backward"]] = false;
    _keystates[_keyconf["strafe_left"]] = false;
    _keystates[_keyconf["strafe_right"]] = false;
    _keystates[_keyconf["boost"]] = false;

    // SDL_WM_GrabInput(SDL_GRAB_ON);
    // SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void FreeFlyCamera::OnMouseMotion(const SDL_MouseMotionEvent & event)
{
	std::cout << "state:" << event.state << "\n";
	std::cout << "xrel:" << event.xrel << "\n";
	std::cout << "yrel:" << event.yrel << "\n";
	std::cout << "x:" << event.x << "\n";
	std::cout << "y:" << event.y << "\n";

	if(event.xrel*event.xrel > 1 || event.yrel *event.yrel>1){

		_theta -= event.xrel*_sensivity;
		_phi -= event.yrel*_sensivity;
		VectorsFromAngles();

	}
}

void FreeFlyCamera::OnMouseWheel(const SDL_MouseWheelEvent & event)
{

    if(event.type == SDL_MOUSEWHEEL)
    {
        if(event.y > 0) // scroll up
        {
             // Put code for handling "scroll up" here!
             _verticalMotionActive = true;
             _timeBeforeStoppingVerticalMotion = 250;
             _verticalMotionDirection = 1;
        }
        else if(event.y < 0) // scroll down
        {
             // Put code for handling "scroll down" here!
             _verticalMotionActive = true;
             _timeBeforeStoppingVerticalMotion = 250;
             _verticalMotionDirection = -1;
        }

    }

    // if ((event.button == SDL_BUTTON_WHEELUP)&&(event.type == SDL_MOUSEBUTTONDOWN)) //coup de molette vers le haut
    // {
    //     _verticalMotionActive = true;
    //     _timeBeforeStoppingVerticalMotion = 250;
    //     _verticalMotionDirection = 1;

    // }
    // else if ((event.button == SDL_BUTTON_WHEELDOWN)&&(event.type == SDL_MOUSEBUTTONDOWN)) //coup de molette vers le bas
    // {
    //     _verticalMotionActive = true;
    //     _timeBeforeStoppingVerticalMotion = 250;
    //     _verticalMotionDirection = -1;
    // }
}

void FreeFlyCamera::OnKeyboard(const SDL_KeyboardEvent & event)
{
//    std::cout << "key pushed:" << event.keysym.sym << "\n";
//    std::cout << "unicode:" << unicode << "\n";
//    std::cout << "key pushed unicode:" << event.keysym.sym.unicode << "\n";

	for (KeyStates::iterator it = _keystates.begin();it != _keystates.end();
            it++)
    {
        if (event.keysym.sym == it->first)
        {
            it->second = (event.type == SDL_KEYDOWN);
            break;
        }
    }

//   std::cout << "freeflycamera infos : backward:" << _keystates[_keyconf["backward"]] << "\n";
//   std::cout << "freeflycamera infos : forward:" << _keystates[_keyconf["forward"]] << "\n";
//   std::cout << "freeflycamera infos : left:" << _keystates[_keyconf["strafe_left"]] << "\n";
//   std::cout << "freeflycamera infos : right:" << _keystates[_keyconf["strafe_right"]] << "\n";
//   std::cout << "freeflycamera infos : phi:" << _phi << "\n";
//   std::cout << "freeflycamera infos : theta:" << _theta << "\n";

}

void FreeFlyCamera::animate(Uint32 timestep)
{
    double realspeed = (_keystates[_keyconf["boost"]])?10*_speed:_speed;
    if (_keystates[_keyconf["forward"]])
        _position += _forward * (realspeed * timestep);
    if (_keystates[_keyconf["backward"]])
        _position -= _forward * (realspeed * timestep);
    if (_keystates[_keyconf["strafe_left"]])
        _position += _left * (realspeed * timestep);
    if (_keystates[_keyconf["strafe_right"]])
        _position -= _left * (realspeed * timestep);
    if (_verticalMotionActive)
    {
        if (timestep > _timeBeforeStoppingVerticalMotion)
            _verticalMotionActive = false;
        else
            _timeBeforeStoppingVerticalMotion -= timestep;
        _position += Vector3D(0,_verticalMotionDirection*realspeed*timestep,0);
    }
    _target = _position + _forward;

}

void FreeFlyCamera::setSpeed(double speed)
{
    _speed = speed;
}

void FreeFlyCamera::setSensivity(double sensivity)
{
    _sensivity = sensivity;
}

void FreeFlyCamera::setPosition(const Vector3D & position)
{
    _position = position;
    _target = _position + _forward;
}

void FreeFlyCamera::VectorsFromAngles()
{
    static const Vector3D up(0,1,0);
    if (_phi > 89)
        _phi = 89;
    else if (_phi < -89)
        _phi = -89;
    double r_temp = cos(_phi*M_PI/180);
    _forward.Y = sin(_phi*M_PI/180);
    _forward.Z = r_temp*cos(_theta*M_PI/180);
    _forward.X = r_temp*sin(_theta*M_PI/180);

    _left = up.crossProduct(_forward);
    _left.normalize();

    _target = _position + _forward;
}

void FreeFlyCamera::look()
{
    gluLookAt(_position.X,_position.Y,_position.Z,
              _target.X,_target.Y,_target.Z,
              0,1,0);
}

FreeFlyCamera::~FreeFlyCamera()
{
    SDL_WM_GrabInput(SDL_GRAB_OFF);
    SDL_ShowCursor(SDL_ENABLE);
}
