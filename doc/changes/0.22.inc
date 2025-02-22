.. NOTE: we are now using links to highlight new functions and classes.
   Please follow the examples below like :func:`mne.stats.f_mway_rm`, so the
   whats_new page will have a link to the function/class documentation.

.. NOTE: there are 3 separate sections for changes, based on type:
   - "Enhancements" for new features
   - "Bugs" for bug fixes
   - "API changes" for backward-incompatible changes

.. _changes_0_22:

Version 0.22.0 (2020-12-17)
---------------------------

.. |Austin Hurst| replace:: **Austin Hurst**

.. |Aniket Pradhan| replace:: **Aniket Pradhan**

.. |Eduard Ort| replace:: **Eduard Ort**

.. |Evan Hathaway| replace:: **Evan Hathaway**

.. |Hongjiang Ye| replace:: **Hongjiang Ye**

.. |Jeff Stout| replace:: **Jeff Stout**

.. |Jonathan Kuziek| replace:: **Jonathan Kuziek**

.. |Qianliang Li| replace:: **Qianliang Li**

.. |Tod Flak| replace:: **Tod Flak**

.. |Victoria Peterson| replace:: **Victoria Peterson**


Enhancements
~~~~~~~~~~~~
- Add :func:`mne.read_evokeds_mff` to read averaged MFFs (requires mffpy >= 0.5.7) **by new contributor** |Evan Hathaway|_ (:gh:`8354`)

- Add :class:`mne.decoding.SSD` for spatial filtering with spatio-spectral-decomposition (:gh:`7070` **by new contributor** |Victoria Peterson|_ and `Denis Engemann`_)

- Add reader for optical imaging data recorded using ISS Imgagent I/II hardware and BOXY recording software in :func:`mne.io.read_raw_boxy` (:gh:`7717` **by new contributor** |Jonathan Kuziek|_ and `Kyle Mathewson`_)

- Add options to use labels in :func:`mne.minimum_norm.get_point_spread` and :func:`mne.minimum_norm.get_cross_talk` (:gh:`8275` by `Olaf Hauk`_)

- Update ``surfaces`` argument in :func:`mne.viz.plot_alignment` to allow dict for transparency values, and set default for sEEG data to have transparency (:gh:`8445` by `Keith Doelling`_)

- Add support for ``mri_fiducials='estimated'`` in :func:`mne.viz.plot_alignment` to allow estimating MRI fiducial locations using :func:`mne.coreg.get_mni_fiducials` (:gh:`8553` by `Eric Larson`_)

- Update default values in :ref:`mne coreg` and :func:`mne.viz.plot_alignment` for clearer representation of MRI and digitized fiducial points (:gh:`8553` by `Alex Gramfort`_ and `Eric Larson`_)

- Add ``n_pca_components`` argument to :func:`mne.viz.plot_ica_overlay` (:gh:`8351` by `Eric Larson`_)

- Add :func:`mne.stc_near_sensors` to facilitate plotting ECoG data (:gh:`8190` by `Eric Larson`_)

- Add ``proj`` argument to :func:`mne.make_fixed_length_epochs` (:gh:`8351` by `Eric Larson`_)

- Add :func:`mne.preprocessing.realign_raw` to realign simultaneous raw recordings in the presence of clock drift (:gh:`8539` by `Eric Larson`_)

- Reduce memory usage of volume source spaces (:gh:`8379` by `Eric Larson`_)

- Speed up heavy use of :meth:`mne.SourceMorph.apply` for volumetric source spaces by use of the method :meth:`mne.SourceMorph.compute_vol_morph_mat` (:gh:`8366` by `Eric Larson`_)

- Add support for non-uniform ``zooms`` (e.g., when using a surrogate MRI via :func:`mne.scale_mri`) in volumetric morphing  (:gh:`8642` by `Eric Larson`_)

- In :func:`mne.compute_source_morph` ``zooms`` are no longer required to match the spacing of ``src_to``, which is useful to ensure the morphing is accurate when the ``src_to`` spacing is large (e.g., 1 cm) (:gh:`8642` by `Eric Larson`_)

- Add volumetric source space support to :func:`mne.labels_to_stc` (:gh:`8447` by `Eric Larson`_)

- Speed up :class:`mne.decoding.TimeDelayingRidge` with edge correction using Numba (:gh:`8323` by `Eric Larson`_)

- Add :meth:`mne.Epochs.reset_drop_log_selection` to facilitate writing epochs with many ignored entries in their drop log (:gh:`8449` by `Eric Larson`_)

- Add sEEG source visualization using :func:`mne.stc_near_sensors` and sEEG working tutorial (:gh:`8402` by `Eric Larson`_ and `Adam Li`_)

- Add :meth:`mne.channels.DigMontage.get_positions`, which will return a dictionary of channel positions, coordinate frame and fiducial locations (:gh:`8460` by `Adam Li`_)

- Add support for writing digitization points in a coordinate frame other than head in :meth:`mne.channels.DigMontage.save` (:gh:`8532` by `Eric Larson`_)

- Add ``picks`` parameter to :func:`mne.preprocessing.fix_stim_artifact` to specify which channel needs to be fixed (:gh:`8482` by `Alex Gramfort`_)

- Add progress bar support to :func:`mne.time_frequency.csd_morlet` (:gh:`8608` by `Eric Larson`_)

- Further improved documentation building instructions and execution on Windows (:gh:`8502` by `kalenkovich`_ and `Eric Larson`_)

- Add option to disable TQDM entirely with ``MNE_TQDM='off'`` (:gh:`8515` by `Eric Larson`_)

- Add option ``on_header_missing`` to :func:`mne.channels.read_polhemus_fastscan` (:gh:`8622` by `Eric Larson`_)

- Add option ``window`` to :func:`mne.time_frequency.psd_welch` and related functions (:gh:`8862` by `Eric Larson`_)

- `mne.preprocessing.ICA.plot_sources` now displays an `mne.preprocessing.ICA.plot_properties` window when right-clicking on component names on the y-axis (:gh:`8381` by `Daniel McCloy`_)

- :func:`mne.io.read_raw_edf`, :func:`mne.io.read_raw_bdf`, and :func:`mne.io.read_raw_gdf` now detect and handle invalid highpass/lowpass filter settings (:gh:`8584` by `Clemens Brunner`_)

- If a ``baseline`` tuple containing one or two ``None`` values – e.g. ``(None, 0)``, ``(0, None)``, or ``(None, None)`` – is passed to `~mne.Epochs` or `~mne.Epochs.apply_baseline`, the ``None`` value(s) will be replaced with the actual time (i.e., :attr:`~mne.Epochs.tmin` and :attr:`~mne.Epochs.tmax`, respectively) when populating ``Epochs.baseline`` (:gh:`8442` by `Richard Höchenberger`_)

- `~mne.Epochs` will now retain the information about an applied baseline correction, even if the baseline period is partially or completely removed through cropping later on (:gh:`8442` by `Richard Höchenberger`_)

- Add :func:`mne.source_space.compute_distance_to_sensors` to compute distances between vertices and sensors (:gh:`8534` by `Olaf Hauk`_ and `Marijn van Vliet`_)

- Annotations can now be shown/hidden interactively in raw plots (:gh:`8624` by `Daniel McCloy`_)

- Added argument ``colors`` to `mne.grow_labels` (:gh:`8519` by `Olaf Hauk`_)

- Added `mne.SourceEstimate.apply_baseline` method for baseline-correction of source estimates (:gh:`8452` by `Olaf Hauk`_)

- New `mne.viz.Brain.set_time` method to set the displayed time in seconds (:gh:`8415` by `Daniel McCloy`_)

- Update the ``backend`` parameter of :func:`mne.viz.plot_source_estimates` to integrate ``pyvista`` (:gh:`8395` by `Guillaume Favelier`_)

- Add ``group_by`` parameter to `mne.viz.plot_epochs` and `mne.Epochs.plot` to allow displaying channel data by sensor position (:gh:`8381` by `Daniel McCloy`_)

Bugs
~~~~
- Fix orthogonalization of power envelopes in ``mne.connectivity.envelope_correlation`` (:gh:`8658` **by new contributor** |Qianliang Li|_ and `Eric Larson`_)

- Fix data overwrite of cascading simulation operations :`mne.simulation.simulate_raw` (:gh:`8633` **by new contributor** |Jeff Stout|_)

- Fix a transpose issue of :func:`mne.decoding.CSP.plot_filters` (:gh:`8580` **by new contributor** |Hongjiang Ye|_)

- Fix :func:`mne.io.read_raw_curry` to deal with Curry datasets that have channels that are listed in the labels file, but which are absent from the saved data file (e.g. 'Ref' channel).  Also now populates info['meas_date'] if possible (:gh:`8400` **by new contributor** |Tod Flak|_)

- Fix bug with mne.io.egi.tests/test_egi.py where it mandatorily downloaded testing data when it was not necessary (:gh:`8474` **by new contributor** |Aniket Pradhan|_)

- Fix bug with reading split files that have dashes in the filename (:gh:`8339` **by new contributor** |Eduard Ort|_)

- Fix bug with parsing EDF dates and date integers (:gh:`8558` **by new contributor** |Austin Hurst|_ and `Eric Larson`_)

- Fix bug with reading EDF and KIT files on big endian architectures such as s390x (:gh:`8618` by `Eric Larson`_)

- Fix bug with :func:`mne.beamformer.make_dics` where the ``rank`` parameter was not properly handled (:gh:`8594` by `Marijn van Vliet`_ and `Eric Larson`_)

- Fix bug with :func:`mne.beamformer.apply_dics` where the whitener was not properly applied (:gh:`8610` by `Eric Larson`_)

- Fix bug with `~mne.viz.plot_epochs_image` when ``order`` is supplied and multiple conditions are plotted (:gh:`8377` by `Daniel McCloy`_ )

- Fix bug with :func:`mne.viz.plot_source_estimates` when using the PyVista backend where singleton time points were not handled properly (:gh:`8285` by `Eric Larson`_)

- Fix bug when passing ``axes`` to plotting functions, :func:`matplotlib.pyplot.tight_layout` will not be called when the figure was created using a constrained layout (:gh:`8344` by `Eric Larson`_)

- Fix bug with compensated CTF data when picking channels without preload (:gh:`8318` by `Eric Larson`_)

- Fix bug with plotting MEG topographies where the wrong extrapolation made was used in ICA (:gh:`8637` by `Eric Larson`_)

- Fix bug when merging fNIRS channels in :func:`mne.viz.plot_evoked_topomap` and related functions (:gh:`8306` by `Robert Luke`_)

- Fix bug where events could overflow when writing to FIF (:gh:`8448` by `Eric Larson`_)

- :func:`mne.io.read_raw_edf` now supports EDF files with invalid recording dates (:gh:`8283` by `Clemens Brunner`_)

- Fix bug with :func:`mne.io.Raw.save` when using ``split_naming='bids'`` where non-split files would still be named ``name_split-01_meg.fif`` instead of the requested ``name_meg.fif`` (:gh:`8464` by `Alex Gramfort`_ and `Eric Larson`_)

- Fix bug with :class:`mne.preprocessing.ICA` where ``n_pca_components`` as a :class:`python:float` would give the number of components that explained less than or equal to the given variance. It now gives greater than the given number for better usability and consistency with :class:`sklearn.decomposition.PCA`. Generally this will mean that one more component will be included (:gh:`8326` by `Eric Larson`_)

- Fix bug with :class:`mne.preprocessing.ICA` where projections were not tracked properly (:gh:`8343` by `Eric Larson`_)

- Fix bug where extrapolation points created artifacts in :func:`mne.viz.plot_evoked_topomap` and related functions (:gh:`8425` by `Mikołaj Magnuski`_)

- Fix bug with :func:`mne.preprocessing.read_ica_eeglab` where full-rank data were not handled properly (:gh:`8326` by `Eric Larson`_)

- Fix bug with :ref:`somato-dataset` where the BEM was not included (:gh:`8317` by `Eric Larson`_)

- Fix bug with coordinate frames when performing volumetric morphs via :func:`mne.compute_source_morph` and :meth:`mne.SourceMorph.apply` that could lead to ~5 mm bias (:gh:`8642` by `Eric Larson`_)

- Fix bug with volumetric rendering alpha in :meth:`mne.VolSourceEstimate.plot_3d` and related functions (:gh:`8663` by `Eric Larson`_)

- Fix missing documentation of :func:`mne.io.read_raw_nihon` in :ref:`tut-imorting-eeg-data` (:gh:`8320` by `Adam Li`_)

- Fix bug with :func:`mne.add_reference_channels` when :func:`mne.io.Raw.reorder_channels` or related methods are used afterward (:gh:`8303`, :gh:`#8484` by `Eric Larson`_)

- Fix bug where the ``verbose`` arguments to :meth:`mne.Evoked.apply_baseline` and :meth:`mne.Epochs.apply_baseline` were not keyword-only (:gh:`8349` by `Eric Larson`_)

- ``ICA.max_pca_components`` will not be altered by calling `~mne.preprocessing.ICA.fit` anymore. Instead, the new attribute ``ICA.max_pca_components_`` will be set (:gh:`8321` by `Richard Höchenberger`_)

- Fix bug that `~mne.viz.plot_ica_overlay` would sometimes not create red traces (:gh:`8341` by `Richard Höchenberger`_)

- Fix bug with :class:`~mne.preprocessing.ICA` where ``n_components=None, n_pca_components=None`` could lead to unstable unmixing matrix inversion by making ``n_components=None`` also use the lesser of ``n_components=0.999999`` and ``n_components=n_pca_components`` (:gh:`8351` by `Eric Larson`_)

- The ``ica.n_pca_components`` property is no longer be updated during :meth:`mne.preprocessing.ICA.fit`, instead ``ica.n_components_`` will be added to the instance (:gh:`8351` by `Eric Larson`_)

- Pass ``rank`` everyhwere in forward preparation for source imaging. This bug affected sparse solvers when using maxfilter data  (:gh:`8368` by `Alex Gramfort`_)

- Fix bug in :func:`mne.viz.plot_alignment` where ECoG and sEEG channels were not plotted and fNIRS channels were always plotted in the head coordinate frame (:gh:`8393` by `Eric Larson`_)

- Fix bug in :func:`mne.set_bipolar_reference` where ``ch_info`` could contain invalid channel information keys (:gh:`8416` by `Eric Larson`_)

- When reading BrainVision raw data, the channel units and types were sometimes not inferred correctly (:gh:`8434` by `Richard Höchenberger`_)

- Attempting to remove baseline correction from preloaded `~mne.Epochs` will now raise an exception (:gh:`8435` by `Richard Höchenberger`_)

- :meth:`mne.Report.parse_folder` will now correctly handle split FIFF files (:gh:`8486`, :gh:`8491` by `Richard Höchenberger`_)

- Fix bug where BrainVision channel names, event types, and event descriptions containing commas were incorrectly parsed (:gh:`8492` by `Stefan Appelhoff`_)

- Fix bug in :func:`mne.preprocessing.compute_fine_calibration` where the magnetometer calibration coefficients were computed incorrectly (:gh:`8522` by `Eric Larson`_)

- Fix bug in :func:`mne.io.read_raw_eeglab` where empty event durations led to an error (:gh:`8384` by `Mikołaj Magnuski`_)

- Fix inset sensor plots to always use equal aspect (:gh:`8545` by `Daniel McCloy`_)

- Fix bug in `mne.viz.plot_compare_evokeds` where evokeds with identical ``comment`` attributes would not plot properly if passed as a list (:gh:`8590` by `Daniel McCloy`_)

- Fix bug in :func:`mne.time_frequency.psd_welch` and related functions where the window default errantly changed from ``'hamming'`` to ``('tukey', 0.25)`` (:gh:`8862` by `Eric Larson`_)

- Fix bug in :func:`mne.io.read_raw_kit` where scale factors for EEG channels could be set to zero (:gh:`8542` by `Eric Larson`_)

- Fix reading GDF files with excluded channels in :func:`mne.io.read_raw_gdf` (:gh:`8520` by `Clemens Brunner`_)

- Fix automatic selection of extrapolation mask type from channel type when plotting field maps (:gh:`8589` by `Daniel McCloy`_)

- Fix bug in :func:`mne.viz.set_3d_title` where 3D plot could have multiple titles that overlap (:gh:`8564` by `Guillaume Favelier`_)

- Fix bug in :func:`mne.viz.set_3d_view` where plotter is not updated properly causing camera issues in the doc (:gh:`8564` by `Guillaume Favelier`_)

- :func:`mne.preprocessing.find_ecg_events` didn't take the ``tstart`` parameter value into account when calculating the average heart rate (:gh:`8605` by `Richard Höchenberger`_)

API changes
~~~~~~~~~~~

- Minimum required versions were increased for core dependencies NumPy (1.15.4), SciPy (1.1.0), and Matplotlib (3.0) and for the optional dependencies scikit-learn (0.20.2) and pandas (0.23.4) (:gh:`8374` by `Eric Larson`_)

- The parameter ``on_split_missing`` has been added to :func:`mne.io.read_raw_fif` and its default will change from ``'warn'`` to ``'raise'`` in 0.23, by (:gh:`8357` `Eric Larson`_)

- The ``max_pca_components`` argument of :class:`~mne.preprocessing.ICA` has been deprecated, use ``n_components`` during initialization and ``n_pca_components`` in :meth:`~mne.preprocessing.ICA.apply` instead (:gh:`8351` by `Eric Larson`_)

- The ``n_pca_components`` argument of :class:`~mne.preprocessing.ICA` has been deprecated, use ``n_pca_components`` in :meth:`~mne.preprocessing.ICA.apply` (:gh:`8356` by `Eric Larson`_)

- The ``trans`` argument of :func:`mne.extract_label_time_course` is deprecated and will be removed in 0.23 as it is no longer necessary (:gh:`8389` by `Eric Larson`_)

- Parameter ``event_colors`` in `mne.viz.plot_epochs` and `mne.Epochs.plot` is deprecated, replaced by ``event_color`` which is consistent with `mne.viz.plot_raw` and provides greater flexibility (:gh:`8381` by `Daniel McCloy`_)

Authors
~~~~~~~

People who contributed to this release in alphabetical order
(people with a + are first time contributors):

* Adam Li
* Alexandre Gramfort
* Aniket Pradhan +
* Austin Hurst +
* Christian Brodbeck
* Clemens Brunner
* Daniel McCloy
* Denis A. Engemann
* Eduard Ort +
* Eric Larson
* Evan Hathaway +
* Evgenii Kalenkovich
* Fede Raimondo
* Guillaume Favelier
* Hongjiang Ye +
* Jean-Remi King
* Jeff Stout +
* Jonathan Kuziek +
* Jussi Nurminen
* Justus Schwabedal
* Keith Doelling
* Kyle Mathewson
* Mads Jensen
* Mainak Jas
* Marijn van Vliet
* Mikolaj Magnuski
* Olaf Hauk
* Qianliang Li +
* Richard Höchenberger
* Robert Luke
* Stefan Appelhoff
* Thomas Hartmann
* Tod Flak +
* Victoria Peterson +
