#define SHOW_LAYER_CHANGE                                                                          \
    (IS_ENABLED(CONFIG_RGBLED_WIDGET_SHOW_LAYER_CHANGE)) &&                                        \
        (!IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))

#define SHOW_LAYER_COLORS                                                                          \
    (IS_ENABLED(CONFIG_RGBLED_WIDGET_SHOW_LAYER_COLORS)) &&                                        \
        (!IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)
void indicate_battery(void);
#endif

#if IS_ENABLED(CONFIG_ZMK_BLE)
void indicate_connectivity(void);
#endif

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
void indicate_layer(void);
#endif

#if SHOW_LAYER_COLORS
/**
 * @brief Colour index currently assigned to a layer (0 = off).
 */
uint8_t zmk_rgbled_widget_get_layer_color(uint8_t layer);

/**
 * @brief Assign a layer's colour and persist it.
 *
 * Called by ZMK Studio's set_layer_props handler. Out-of-range layers and
 * colours are ignored rather than clamped, so a bad request cannot silently
 * recolour the wrong layer.
 */
void zmk_rgbled_widget_set_layer_color(uint8_t layer, uint8_t color);
#endif
