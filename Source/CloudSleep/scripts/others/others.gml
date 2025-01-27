#macro while_ until !

randomize();


function DrawChat(_x, _y, _chatText) {
	draw_set_color(c_black);
	draw_set_font(fontRegular);
	
	var baseWidth = 58;
	
	draw_sprite_ext(spr_ChatBackground, 0, _x, _y + 2, (string_width(_chatText) + baseWidth) / sprite_get_width(spr_ChatBackground), 1, 0, c_white, 0.8);
	draw_set_alpha(0.8);
	draw_sprite(spr_ChatBackgroundTail, 0, _x, _y + 2);
	
	draw_set_alpha(1.0);
	
	draw_set_halign(fa_center);
	draw_set_valign(fa_middle);
	draw_text(_x, _y, _chatText);
	draw_set_halign(fa_left);
	draw_set_valign(fa_top);
	
	draw_set_color(c_white);
}

