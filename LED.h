#pragma once

#include <cstdint>
#include <forward_list>

namespace r2led {

class LED
{
    private:
        std::uint32_t trans(std::uint8_t color);
    public:		
	~LED();

        std::forward_list<std::uint8_t*> temp_colors;
        
        std::uint8_t* trans_color(std::uint8_t r, std::uint8_t g, std::uint8_t b);
        std::uint8_t* write_color(std::uint8_t* color);
	void trans_list();
	// std::uint8_t* procissing_colors(const std::forward_list<std::uint8_t*>& set_colors);
};

};  // namespace r2led
