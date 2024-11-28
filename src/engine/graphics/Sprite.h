#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <cstddef>
#include <iostream>
#include <vector>

class Sprite {
private:
  sf::Sprite _sprite;                       // Main sprite
  sf::Texture _texture;                     // Texture of sprite
  sf::Vector2f _velocity;                   // Speed of sprite
  sf::Vector2f _acceletation;               // acceleration of sprite
  std::vector<sf::IntRect> _animationFrame; // All frame for animation of sprite
  size_t _currentFrame;                     // Current frame
  float _frameTime;                         // Time of frame
  float _elapsedTime;                       //
  bool _isActive;                           // Activity of sprite
  bool _isVisible;                          // Visible of sprite

public:
  Sprite(sf::String fileName, float width, float height);
  bool loadTexture(const std::string &path);
  bool checkCollision(const Sprite &other);
  bool isVisible();

  void update(float deltaTime);
  void draw(sf::RenderWindow &window);
  void addAnimationFrame(const sf::IntRect &frame);
  void playAnimation();
  void stopAnimation();

  void setPosition(float x, float y);
  void setVelocity(float vx, float vy);
  void setVisible(bool isVisible);

  sf::Vector2f getPosition();

  void update();
};

Sprite::Sprite(sf::String fileName, float width, float height) {}

bool Sprite::loadTexture(const std::string &path) {
  if (_texture.loadFromFile(path)) {
    return false;
  }
  _sprite.setTexture(_texture);
  return true;
}

bool Sprite::checkCollision(const Sprite &other) {
  return _sprite.getGlobalBounds().intersects(other._sprite.getGlobalBounds());
}

#endif // SPRITE_H
