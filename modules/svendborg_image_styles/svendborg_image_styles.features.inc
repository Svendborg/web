<?php
/**
 * @file
 * svendborg_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function svendborg_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: svendborg_content_image.
  $styles['svendborg_content_image'] = array(
    'name' => 'svendborg_content_image',
    'label' => 'svendborg_content_image',
    'effects' => array(
      18 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'dimensions callback' => 'epsacrop_crop_dimensions',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 918,
          'height' => 432,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'white',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => -10,
      ),
      21 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 918,
          'height' => 432,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: svendborg_spotbox.
  $styles['svendborg_spotbox'] = array(
    'name' => 'svendborg_spotbox',
    'label' => 'svendborg_spotbox',
    'effects' => array(
      12 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'dimensions callback' => 'epsacrop_crop_dimensions',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 272,
          'height' => 126,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => 2.15,
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
      22 => array(
        'label' => 'Skalér og beskær',
        'help' => 'Skalering og beskæring bevarer billedets højde-bredde-forhold og beskærer derefter den største dimension. Det er nyttigt til at generere kvadratiske thumbnails uden at forvrænge billedet.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 272,
          'height' => 126,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
